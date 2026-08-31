/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:46:05 by tmalyshi          #+#    #+#             */
/*   Updated: 2026/08/31 16:05:59 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	*stack = (*stack)->next;
}

int	ra(t_data *data)
{
	if ((!data->stack_a) || (!data->stack_a->next))
		return (0);
	ft_rotate(&data->stack_a);
	data->ops.ra_count++;
	data->ops.total_count++;
	ft_printf_fd(1, "ra\n");
	return (1);
}

int	rb(t_data *data)
{
	if ((!data->stack_b) || (!data->stack_b->next))
		return (0);
	ft_rotate(&data->stack_b);
	data->ops.rb_count++;
	data->ops.total_count++;
	ft_printf_fd(1, "rb\n");
	return (1);
}

int	rr(t_data *data)
{
	if ((!data->stack_a) || (!data->stack_b))
		return (0);
	ft_rotate(&data->stack_a);
	ft_rotate(&data->stack_b);
	data->ops.rr_count++;
	data->ops.total_count++;
	ft_printf_fd(1, "rr\n");
	return (1);
}
