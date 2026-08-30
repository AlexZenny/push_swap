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

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_b))
		return (0);
	push(stack_b, stack_a);
	ft_printf_fd(1, "pa\n");
	return (1);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_a))
		return (0);
	push(stack_a, stack_b);
	ft_printf_fd(1, "pb\n");
	return (1);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	t_list *lst_a1 = malloc(sizeof(t_list));
// 	t_list *lst_a2 = malloc(sizeof(t_list));	
// 	t_list *lst_a3 = malloc(sizeof(t_list));	
// 	t_list *lst_b1 = malloc(sizeof(t_list));
// 	t_list *lst_b2 = malloc(sizeof(t_list));
// 	t_list *lst_b3 = malloc(sizeof(t_list));
//
// 	lst_a1->next = lst_a2;
// 	lst_a1->prev = lst_a3;
// 	lst_a2->next = lst_a3;
// 	lst_a2->prev = lst_a1;	
// 	lst_a3->next = lst_a1;
// 	lst_a3->prev = lst_a2;
// 	lst_a1->value = 1;
// 	lst_a2->value = 2;	
// 	lst_a3->value = 3;	
// 	lst_b1->next = lst_b2;
// 	lst_b1->prev = lst_b3;
// 	lst_b2->next = lst_b3;
// 	lst_b2->prev = lst_b1;	
// 	lst_b3->next = lst_b1;
// 	lst_b3->prev = lst_b2;
// 	lst_b1->value = 4;
// 	lst_b2->value = 5;
// 	lst_b3->value = 6;
//
// 	printf("pre: a1 == %d, a2 == %d, a3 == %d\n", lst_a1->value, 
// 			lst_a1->next->value, lst_a1->next->next->value);
// 	printf("pre: b1 == %d, b2 == %d, b3 == %d\n", lst_b1->value, 
// 			lst_b1->next->value, lst_b1->next->next->value);
// 	push(&lst_a1, &lst_b1);
// 	printf("pre: a1 == %d, a2 == %d, a3 == %d\n", lst_a1->value,
// 			lst_a1->next->value, lst_a1->next->next->value);
// 	printf("pre: b1 == %d, b2 == %d, b3 == %d\n", lst_b1->value,
// 			lst_b1->next->value, lst_b1->next->next->value);
// }
