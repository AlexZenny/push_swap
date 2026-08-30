/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:33:55 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/23 22:42:51 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*temp;

	temp = (*stack);
	*stack = temp->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	(*stack)->prev = temp->prev;
	temp->prev = (*stack);
	temp->next->prev = temp;
	(*stack)->prev->next = *stack;
}

int	sa(t_list **stack_a)
{
	if ((!(*stack_a)) || (!(*stack_a)->next))
		return (0);
	swap(stack_a);
	return (1); 
}

int	sb(t_list **stack_b)
{
	if ((!(*stack_b)) || (!(*stack_b)->next))
		return (0);
	swap(stack_b);
	return (1); 
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if ((!(*stack_a)) || (!(*stack_a)->next)
		|| (!(*stack_b)) || (!(*stack_b)->next))
		return (0);
	swap(stack_a);
	swap(stack_b);
	return (1);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	t_list *lst_a1 = malloc(sizeof(t_list));
// 	t_list *lst_a2 = malloc(sizeof(t_list));	
// 	t_list *lst_b1 = malloc(sizeof(t_list));
// 	t_list *lst_b2 = malloc(sizeof(t_list));
//
// 	lst_a1->next = lst_a2;
// 	lst_a1->value = 1;
// 	lst_a2->value = 2;	
// 	lst_b1->next = lst_b2;
// 	lst_b1->value = 1;
// 	lst_b2->value = 2;
//
// 		printf("pre: a1 == %d, a2 == %d\n", lst_a1->value, lst_a1->next->value);
// 		printf("pre: b1 == %d, b2 == %d\n", lst_b1->value, lst_b1->next->value);
// 		swap_both(&lst_a1, &lst_b1);
// 		printf("aft: a1 == %d, a2 == %d\n", lst_a1->value, lst_a1->next->value);
// 		printf("pre: b1 == %d, b2 == %d\n", lst_b1->value, lst_b1->next->value);
// }
