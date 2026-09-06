/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:31:03 by azieniuk          #+#    #+#             */
/*   Updated: 2026/09/05 14:48:23 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int set_algorithm(t_options *opt, t_mode mode)
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

int	main(int argc, char **argv)
{
	t_data	data;
	float	disorder;

	(void)argc;
	initialize_data(&data);
	if (parse_input(argv, &data))
		ft_printf_fd(2, "Error\n");
	if (is_sorted(&data.stack_a))
		return (0);
	disorder = calculate_disorder(&data.stack_a);
	initialize_counters(&data);
	select_sort(&data, disorder);
	if (data.options.bench == true)
		benchmark_mode(&data, disorder);
	ft_deallocate(&data.stack_b);
	return (0);
}
// #include <stdio.h>
//
// int	main(void)
// {
// 	char	*str = "1 2 3";
// 	int		res;
//
// 	res = parse_arg(res);
// 	if (res)
// 		printf("Error\n");
// 	else
// 		printf("Success\n");
// }
