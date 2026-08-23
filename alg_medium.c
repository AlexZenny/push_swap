/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_medium.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 21:15:21 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/23 19:36:07 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_list **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	*stack = (*stack)->prev;
}

void	ft_rotate(t_list **stack)
{
	t_list	*temp;

	if (stack == NULL || *stack == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = temp;
}

void	swap(t_list **lst)
{
	t_list	*temp;

	if ((!(*lst)) || (!(*lst)->next))
		return ;
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = *lst;
	*lst = temp;
}

void	limited_insertion_sort(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	int		i;
	bool	forward;

	if (!(*stack_a))
		return ;
	i = 0;
	while ((i++) < chunk_size)
		push(stack_a, stack_b);
	forward = true;
	i = 0;
	while ((i++) < chunk_size)
	{
		if ((*stack_b)->value > (*stack_b)->next->value)
		{
			swap(stack_b);
			forward = !forward;
			i = 0;
		}
		if (forward)
			ft_rotate(stack_b);
		else
			ft_rev_rotate(stack_b);
	}
}

// void	chunk_merge_sort(t_list **stack_a, t_list **stack_b, int n)
// {
// 	int	chunk_size;
// 	int	last_chunk_size;
//
// 	if ((!(*stack_a)) || (!(*stack_b_)))
// 		return ;
// 	chunk_size = ft_sqrt(n);
// 	last_chunk_size = chunk_size;
// 	if (chunk_size * chunk_size < n)
// 		last_chunk_size += n - (chunk_size * chunk_size)
// }

#include <stdio.h>

int main(void)
{
	int	i = 0;
	t_list *lst_a1 = malloc(sizeof(t_list));
	t_list *lst_a2 = malloc(sizeof(t_list));
	t_list *lst_a3 = malloc(sizeof(t_list));
	t_list *lst_a4 = malloc(sizeof(t_list));
	t_list *lst_a5 = malloc(sizeof(t_list));
	t_list *lst_a6 = malloc(sizeof(t_list));
	t_list *lst_a7 = malloc(sizeof(t_list));
	t_list *lst_a8 = malloc(sizeof(t_list));
	t_list *lst_a9 = malloc(sizeof(t_list));
	t_list *lst_a10 = malloc(sizeof(t_list));
	t_list *lst_a11 = malloc(sizeof(t_list));
	t_list *lst_a12 = malloc(sizeof(t_list));
	t_list *lst_a13 = malloc(sizeof(t_list));
	t_list *lst_a14 = malloc(sizeof(t_list));
	t_list *lst_a15 = malloc(sizeof(t_list));
	t_list *lst_a16 = malloc(sizeof(t_list));
	t_list *lst_b1 = NULL;
	lst_a1->next = lst_a2;
	lst_a1->prev = lst_a16;
	lst_a2->next = lst_a3;
	lst_a2->prev = lst_a1;
	lst_a3->next = lst_a4;
	lst_a3->prev = lst_a2;
	lst_a4->next = lst_a5;
	lst_a4->prev = lst_a3;
	lst_a5->next = lst_a6;
	lst_a5->prev = lst_a4;
	lst_a6->next = lst_a7;
	lst_a6->prev = lst_a5;
	lst_a7->next = lst_a8;
	lst_a7->prev = lst_a6;
	lst_a8->next = lst_a9;
	lst_a8->prev = lst_a7;
	lst_a9->next = lst_a10;
	lst_a9->prev = lst_a8;
	lst_a10->next = lst_a11;
	lst_a10->prev = lst_a9;
	lst_a11->next = lst_a12;
	lst_a11->prev = lst_a10;
	lst_a12->next = lst_a13;
	lst_a12->prev = lst_a11;
	lst_a13->next = lst_a14;
	lst_a13->prev = lst_a12;
	lst_a14->next = lst_a15;
	lst_a14->prev = lst_a13;
	lst_a15->next = lst_a16;
	lst_a15->prev = lst_a14;
	lst_a16->next = lst_a1;
	lst_a16->prev = lst_a15;
	lst_a1->value = 42;
	lst_a2->value = -7;
	lst_a3->value = 19;
	lst_a4->value = 83;
	lst_a5->value = 4;
	lst_a6->value = 56;
	lst_a7->value = -21;
	lst_a8->value = 31;
	lst_a9->value = 72;
	lst_a10->value = 5;
	lst_a11->value = 14;
	lst_a12->value = 91;
	lst_a13->value = -3;
	lst_a14->value = 27;
	lst_a15->value = 68;
	lst_a16->value = 11;
	// limited_insertion_sort(&lst_a1, &lst_b1, 16);
	// while ((i++) < 16)
	// {
	// 	printf("%d, ", lst_a1->value);
	// 	lst_a1 = lst_a1->next;
	// }
	while ((i++) <= 14)
		push(&lst_a1, &lst_b1);
	if (lst_a1)
		printf("%d\n", lst_a1->value);
	else
		printf("NULL\n");
}
