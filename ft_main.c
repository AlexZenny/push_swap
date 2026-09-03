/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 21:43:06 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/09/03 22:07:11 by tmalyshi         ###   ########.fr       */
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
int	ft_split_argv (char *argv, char **tokens)
{
	tokens = ft_split(argv, ' ');
	if (tokens == NULL)
		return (NULL);
	if (tokens[0] == NULL)
	{
		free(tokens);
		return(1);
	}
	return (0);
}

int count_tokens(char *argv)
{
	int 	j;
	int		count;

	j = 0;
	count = 0;
	while (argv[j])
	{
		while (argv[j] == ' ')
			j++;
		if (argv[j])
		{
			count++;
			while(argv[j] && argv[j] != ' ')
				j++;
		}
		else 
			return (-1);
	}	
	return(count);
}
int validate_token(char *token, int *array)
{
	long	value;
	
	if (ft_is_number(token) == 0)
	{
		value = ft_atol(token);
		if (value > INT_MAX || value < INT_MIN)
			return (-1);	
		*array = ( int)value;
	}
	return (0);
}
int adding_numbers(char **tokens, int *array)
{
	int		i;
	int		j;

	i = 0;
	j = 0;

	while (tokens[j])
	{
		if (validate_token(&token[j], &array[i]) == 0)
		{
			j++;
			i++;
		}
		else
			return (-1);
	}
	return (0);
}

int *ft_create_array(char *argv[])
{
    int		*array;
    int      i;
	int		count;
	char	**tokens;

    i = 0;
	while (argv[i])
		count = count_tokens(argv[i]);
	if (count == -1)
		return (NULL);
    array = malloc(count*sizeof(*array));
    if (array == NULL)
        return(NULL);
	while ( i < count )
	{
		tokens = ft_split_argv(argv[i]);
		adding_numbers(*token, array);
		i++;
	}
    return(array);
}
int	input_parser(int argc, char *argv[], t_options *options)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (ft_flags(argv[i], options) == 1)
				return (1);
		}
		else if (ft_create_array(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	float	disorder;

	initialize_data(&data);
	if (input_parser(argc, argv, &data.options))
	{
		ft_printf_fd(2, "Error\n");
		return (1);
	}
	if (ft_create_stack(argc, argv, &data.stack_a))
	{
		ft_printf_fd(2, "Error\n");
		ft_deallocate(&data.stack_a);
		return (1);
	}
	if (is_sorted (&data->stack_a) == true)
		return ;
	disorder = calculate_disorder(&data.stack_a);
	initialize_counters(&data);
	select_sort(&data, disorder);
	if (data.options.bench == true)
		benchmark_mode(&data, disorder);
	ft_deallocate(&data.stack_b);
	return (0);
}
