/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 22:12:30 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/31 16:05:36 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_list **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	*stack = (*stack)->prev;
}

int	rra(t_data *data)
{
	if ((!data->stack_a) || (!data->stack_a->next))
		return (0);
	ft_rev_rotate(&data->stack_a);
	data->ops.rra_count++;
	data->ops.total_count++;
	ft_printf_fd(1, "rra\n");
	return (1);
}

int	rrb(t_data *data)
{
	if ((!data->stack_b) || (!data->stack_b->next))
		return (0);
	ft_rev_rotate(&data->stack_b);
	data->ops.rrb_count++;
	data->ops.total_count++;
	ft_printf_fd(1, "rrb\n");
	return (1);
}

int	rrr(t_data *data)
{
	if ((!data->stack_a) || (!data->stack_b))
		return (0);
	ft_rev_rotate(&data->stack_a);
	ft_rev_rotate(&data->stack_b);
	data->ops.rrr_count++;
	data->ops.total_count++;
	ft_printf_fd(1, "rrr\n");
	return (1);
}
