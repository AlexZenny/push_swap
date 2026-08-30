/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:46:05 by tmalyshi          #+#    #+#             */
/*   Updated: 2026/08/30 20:05:33 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
{

	if (stack == NULL || *stack == NULL)
		return ;
	*stack = (*stack)->next;
}
int	ra(t_list **stack_a)
{
	if ((!(*stack_a)) || (!(*stack_a)->next))
		return (0);
	ft_rotate(stack_a);
	ft_printf_fd(1, "ra\n");
	return (1); 
}
int	rb(t_list **stack_b)
{
	if ((!(*stack_b)) || (!(*stack_b)->next))
		return (0);
	ft_rotate(stack_b);
	ft_printf_fd(1, "rb\n");
	return (1); 
}
int	rr(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL || 
		stack_b == NULL || *stack_b == NULL)
		return (0);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf_fd(1, "rr\n");
	return (1);
}
