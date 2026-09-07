/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:31:03 by azieniuk          #+#    #+#             */
/*   Updated: 2026/09/07 02:31:45 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_algorithm(t_options *opt, t_mode mode)
{
	if (opt->mode_status == 1)
		return (1);
	opt->mode = mode;
	opt->mode_status = 1;
	return (0);
}

int	check_flags(char *arg, t_options *opt)
{
	if (!ft_strncmp(arg, "--simple", 9) && !opt->mode_status)
		return (set_algorithm(opt, SIMPLE));
	if (!ft_strncmp(arg, "--medium", 9) && !opt->mode_status)
		return (set_algorithm(opt, MEDIUM));
	if (!ft_strncmp(arg, "--complex", 10) && !opt->mode_status)
		return (set_algorithm(opt, COMPLEX));
	if (!ft_strncmp(arg, "--adaptive", 11) && !opt->mode_status)
		return (set_algorithm(opt, ADAPTIVE));
	if (!ft_strncmp(arg, "--bench", 8) && !opt->bench)
	{
		opt->bench = true;
		return (0);
	}
	return (1);
}

int	error(t_data *data)
{
	ft_printf_fd(2, "Error\n");
	ft_deallocate(&data->stack_a);
	ft_deallocate(&data->stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	float	disorder;

	if (argc == 1)
		return (0);
	initialize_data(&data);
	if (parse_input(argv, &data))
		return (error(&data));
	if (is_sorted(&data.stack_a))
	{
		ft_deallocate(&data.stack_a);
		ft_deallocate(&data.stack_b);
		return (0);
	}
	disorder = calculate_disorder(&data.stack_a);
	initialize_counters(&data);
	adaptive_sort(&data, disorder);
	if (data.options.bench == true && data.stack_a)
		benchmark_mode(&data, disorder);
	ft_deallocate(&data.stack_a);
	ft_deallocate(&data.stack_b);
	return (0);
}
