/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:33:50 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/26 23:28:41 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	detach_lst(t_list **stack, t_list *lst)
{
	if (lst != lst->next)
	{
		*stack = lst->next;
		(*stack)->prev = lst->prev;
		lst->prev->next = *stack;
	}
	else
		*stack = NULL;
}

static void	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*temp;

	temp = *stack_from;
	detach_lst(stack_from, temp);	
	if (*stack_to)
	{
		temp->next = *stack_to;
		temp->prev = (*stack_to)->prev;
		(*stack_to)->prev->next = temp;
		(*stack_to)->prev = temp;
	}
	else
	{
		temp->next = temp;
		temp->prev = temp;
	}
	*stack_to = temp;
}

int	pa(t_data *data)
{
	if (!data)
		return (0);
	push(&data->stack_b, &data->stack_a);	
	ft_printf_fd(1, "pa\n");
	data->ops.pa_count++;
	return (1);
}

int	pb(t_data *data)
{
	if (!data)
		return (0);
	push(&data->stack_a, &data->stack_b);
	ft_printf_fd(1, "pb\n");
	data->ops.pb_count++;
	return (1);
}
