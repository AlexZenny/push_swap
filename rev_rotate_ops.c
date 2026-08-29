/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 22:12:30 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/26 23:33:12 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_list **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	*stack = (*stack)->prev;
}
int	rra(t_list **stack_a)
{
	if ((!(*stack_a)) || (!(*stack_a)->next))
		return (0);
	ft_rev_rotate(stack_a);
	ft_printf_fd(1, "rra\n");
	return (1); 
}
int	rrb(t_list **stack_b)
{
	if ((!(*stack_b)) || (!(*stack_b)->next))
		return (0);
	ft_rev_rotate(stack_b);
	ft_printf_fd(1, "rrb\n");
	return (1); 
}
int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL || 
		stack_b == NULL || *stack_b == NULL)
		return (0);
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	return (1);
}
