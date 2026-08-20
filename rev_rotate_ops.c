/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 22:12:30 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/20 23:51:18 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_list **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	*stack = (*stack)->prev;
}
void	ft_rev_rotate_both(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL || 
		stack_b == NULL || *stack_b == NULL)
		return ;
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
}