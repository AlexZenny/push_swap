/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 21:43:06 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/09/02 12:17:38 by buhankalinu      ###   ########.fr       */
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
char	**ft_valid_number(char *argv)
{
	char	**tokens;
	int		j;

	j = 0;
	tokens = ft_split(argv, ' ');
	if (tokens == NULL)
		return (1);
	if (tokens[0] == NULL)
	{
		free_array(tokens);
		return(1);
	}
	while (tokens[j] != NULL)
	{
		if (ft_is_number(tokens[j]) == 1)
		{
			free_array (tokens);
			return (1);
		}
		j++;
	}
	return (tokens);
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
		else if (ft_valid_number(argv[i]) == 1)
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
	disorder = calculate_disorder(&data.stack_a);
	initialize_counters(&data);
	select_sort(&data, disorder);
	if (data.options.bench == true)
		benchmark_mode(&data, disorder);
	ft_deallocate(&data.stack_b);
	return (0);
}
