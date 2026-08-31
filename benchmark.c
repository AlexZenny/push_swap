/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 19:32:35 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/28 22:11:33 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_complexity(float dis)
{
	if (dis < 0.2)
		ft_printf_fd(2, "O(n^2)\n");
	if (dis > 0.2 && dis < 0.5)
		ft_printf_fd(2, "O(n√n)\n");
	if (dis > 0.5)
		ft_printf_fd(2, "O(n log n)\n");
}

void	benchmark_mode(t_data *data, float dis)
{
	t_mode	*mode;

	mode = &data->options.mode;
	ft_printf_fd(2, "[bench] disorder:	%fd%%\n", dis);
	ft_printf_fd(2, "[bench] strategy:	");
	if (*mode == SIMPLE)
		ft_printf_fd(2, "Simple / O(n^2)\n");
	else if (*mode == MEDIUM)
		ft_printf_fd(2, "Medium / O(n√n)\n");
	else if (*mode == COMPLEX)
		ft_printf_fd(2, "Complex / O(n log n)\n");
	else
	{
		ft_printf_fd(2, "Adaptive / ");
		print_complexity(dis);
	}
	ft_printf_fd(2, "[bench] total_ops:	%d\n", data->ops.total_count);
	ft_printf_fd(2, "[bench] sa:	%d	sb:	%d	ss:	%d	pa:	%d	pb:	%d\n",
			data->ops.sa_count, data->ops.sb_count, data->ops.ss_count,
			data->ops.pa_count, data->ops.pb_count);
	ft_printf_fd(2, "[bench] ra:	%d	rb:	%d	rr:	%d	rra:	%d	rrb:	%d	rrr:	%d\n",
			data->ops.ra_count, data->ops.rb_count, data->ops.rr_count,
			data->ops.rra_count, data->ops.rrb_count, data->ops.rrr_count);
}
