/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 21:43:06 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/09/04 04:04:41 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_mode_status(t_options *options, t_mode mode)
{
	if (options->mode_status == 1)
		return (1);
	options->mode = mode;
	options->mode_status = 1;
	return (0);
}

int	ft_flags(const char *cursor, t_options *options)
{
	if ((ft_strncmp(cursor, "--simple", 9) == 0))
		return (ft_mode_status(options, SIMPLE));
	else if ((ft_strncmp(cursor, "--medium", 9) == 0))
		return (ft_mode_status(options, MEDIUM));
	else if ((ft_strncmp(cursor, "--complex", 10) == 0)
		&& (options->mode_status == 0))
		return (ft_mode_status(options, COMPLEX));
	else if ((ft_strncmp(cursor, "--adaptive", 11) == 0)
		&& (options->mode_status == 0))
		return (ft_mode_status(options, ADAPTIVE));
	else if (ft_strncmp(cursor, "--bench", 8) == 0)
		options->bench = true;
	else
		return (1);
	return (0);
}

char	**ft_split_arg(char *arg)
{
	char	**tokens;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (NULL);
	if (!tokens[0])
	{
		free(tokens);
		return (NULL);
	}
	return (tokens);
}

int	count_tokens(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (argv[i])
	{
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j])
		{
			count++;
			while (argv[i][j] && argv[i][j] != ' ')
				j++;
		}
		else
			return (-1);
		i++;
	}
	return (count);
}

// int	validate_token(char *token, int *arr)
// {
// 	long	value;
// 	
// 	if (ft_is_number(token) == 0)
// 	{
// 		value = ft_atol(token);
// 		if (value > INT_MAX || value < INT_MIN)
// 			return (-1);	
// 		*array = ( int)value;
// 	}
// 	return (0);
// }

// int adding_numbers(char **tokens, int *array)
// {
// 	int		i;
// 	int		j;
//
// 	i = 0;
// 	j = 0;
//
// 	while (tokens[j])
// 	{
// 		if (validate_token(&token[j], &array[i]) == 0)
// 		{
// 			j++;
// 			i++;
// 		}
// 		else
// 			return (-1);
// 	}
// 	return (0);
// }

int	add_numbers_to_array(int *arr, char **tokens)
{
	static int	j = 0;
	int			i;
	long		value;

	i = 0;
	while (tokens[i])
	{
		if (!ft_is_number(tokens[i]))
		{
			value = ft_atol(tokens[i++]);
			if (value > INT_MAX || value < INT_MIN)
				return (1);
			arr[j++] = (int)value;
		}
	}
	return (0);
}

int	ft_create_array(int argc, char **argv, int *arr)
{
	int		i;
	int		count;

    i = 0;
	count = count_tokens(argv);
	if (count == -1)
		return (1);
	arr = malloc(sizeof(int) * count);
    if (!arr)
        return (1);
	while (i++ < argc)
	{
		if (add_numbers_to_array(arr, ft_split_arg(argv[i])))
			return (1);
	}
    return(0);
}

int	input_parser(int argc, char **argv, int *arr, t_options *options)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (ft_flags(argv[i], options))
				return (1);
		}
	}
	if (ft_create_array(argc, argv, arr))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		*arr;
	float	disorder;

	initialize_data(&data);
	if (input_parser(argc, argv, arr, &data.options))
	{
		free(arr);
		ft_printf_fd(2, "Error\n");
		return (1);
	}
	if (ft_create_stack(argc, argv, &data.stack_a))
	{
		ft_printf_fd(2, "Error\n");
		ft_deallocate(&data.stack_a);
		return (1);
	}
	if (is_sorted(&data->stack_a) == true)
		return (0);
	disorder = calculate_disorder(&data.stack_a);
	initialize_counters(&data);
	select_sort(&data, disorder);
	if (data.options.bench == true)
		benchmark_mode(&data, disorder);
	ft_deallocate(&data.stack_b);
	return (0);
}
