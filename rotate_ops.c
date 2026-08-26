/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:46:05 by tmalyshi          #+#    #+#             */
/*   Updated: 2026/08/26 22:52:03 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
{

	if (stack == NULL || *stack == NULL)
		return ;
	*stack = (*stack)->next;
}
void	ft_rotate_both(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL || 
		stack_b == NULL || *stack_b == NULL)
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}




