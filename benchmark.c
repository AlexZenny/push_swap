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

void	benchmark_mode(float dis, t_mode sort, t_ops_counters ops)
{
	ft_printf_fd(2, "[bench] disorder:	%fd%%\n", dis);
	ft_printf_fd(2, "[bench] strategy:	");
	if (sort == SIMPLE)
		ft_printf_fd(2, "Simple / O(n^2)\n");
	else if (sort == MEDIUM)
		ft_printf_fd(2, "Medium / O(n√n)\n");
	else if (sort == COMPLEX)
		ft_printf_fd(2, "Complex / O(n log n)\n");
	else
	{
		ft_printf_fd(2, "Adaptive / ");
		print_complexity(dis);
	}
	ft_printf_fd(2, "[bench] total_ops:	%d\n", ops.total_ops);
	ft_printf_fd(2, "[bench] sa:	%d	sb:	%d	ss:	%d	pa:	%d	pb:	%d\n",
			ops.sa_count, ops.sb_count, ops.ss_count,
			ops.pa_count, ops.pb_count);
	ft_printf_fd(2, "[bench] ra:	%d	rb:	%d	rr:	%d	rra:	%d	rrb:	%d	rrr:	%d\n",
			ops.ra_count, ops.rb_count, ops.rr_count,
			ops.rra_count, ops.rrb_count, ops.rrr_count);
}
