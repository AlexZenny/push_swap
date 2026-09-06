/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:33:55 by azieniuk          #+#    #+#             */
/*   Updated: 2026/09/06 17:30:29 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	*stack = temp->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	temp->prev = (*stack)->prev;
	(*stack)->prev = temp;
	temp->next->prev = temp;
	(*stack)->prev->next = *stack;
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
