/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:33:55 by azieniuk          #+#    #+#             */
/*   Updated: 2026/09/06 21:15:35 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*before;
	t_list	*after;

	first = *stack;
	second = first->next;
	if (second == first->prev)
	{
		*stack = second;
		return ;
	}
	before = first->prev;
	after = second->next;
	before->next = second;
	second->prev = before;
	second->next = first;
	first->prev = second;
	first->next = after;
	after->prev = first;
	*stack = second;
}

int	sa(t_data *data)
{
	if ((!data->stack_a) || (!data->stack_a->next))
		return (0);
	swap(&data->stack_a);
	data->ops.sa_count++;
	data->ops.total_count++;
	ft_printf_fd(1, "sa\n");
	return (1);
}

int	sb(t_data *data)
{
	if ((!data->stack_b) || (!data->stack_b->next))
		return (0);
	swap(&data->stack_b);
	data->ops.sb_count++;
	data->ops.total_count++;
	ft_printf_fd(1, "sb\n");
	return (1);
}

int	ss(t_data *data)
{
	if ((!data->stack_a) || (!data->stack_a->next) || (!data->stack_b)
		|| (!data->stack_b->next))
		return (0);
	swap(&data->stack_a);
	swap(&data->stack_b);
	data->ops.ss_count++;
	data->ops.total_count++;
	ft_printf_fd(1, "ss\n");
	return (1);
}
