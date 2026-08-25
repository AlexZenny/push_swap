/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg_medium.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 21:15:21 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/25 01:07:05 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_list **stack)
{
	if (!(*stack) || (*stack) == (*stack)->prev)
		return ;
	*stack = (*stack)->prev;
}

void	ft_rotate(t_list **stack)
{
	if (!(*stack) || (*stack) == (*stack)->next)
		return ;
	*stack = (*stack)->next;
}

void	experimental_sort(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	int		i;
	bool	back;
	int		ops;

	ops = 0;
	if (!(*stack_a))
		return ;
	i = 0;
	while ((i++) < chunk_size)
	{
		pb(stack_a, stack_b);
		ft_printf("pb\n");
		ops++;
	}
	back = false;
	i = 0;
	while ((i++) < chunk_size)
	{
		if ((*stack_b)->value < (*stack_b)->next->value)
		{
			sb(stack_b);
			ft_printf("sb\n");
			ops++;
			back = !back;
			ft_print_stacks(stack_a, stack_b);
			i = 0;
		}
		if (back)
		{
			ft_rev_rotate(stack_b);
			ft_printf("rrb\n");
			ft_print_stacks(stack_a, stack_b);
			ops++;
		}
		else
		{
			ft_rotate(stack_b);
			ft_printf("rb\n");
			ft_print_stacks(stack_a, stack_b);
			ops++;
		}
	}
	i = 0;
	while ((i++) < chunk_size)
	{
		pa(stack_a, stack_b);
		ft_printf("pa\n");
		ops++;
	}
}

void	merge_chunks(t_list **stack_a, t_list **stack_b, int c_size, int c_count)
{
	int	i;
	int	k;
	int	min;

	i = 0;
	min = (*stack_a)->value;
	while ((i++) < c_count)
	{
		k = 0;
		while ((k++) < c_size)
			ra(stack_a);
		if ((*stack_a)->value < min)
			min = (*stack_a)->value;
	}
}

int main(void)
{
	// int	i = 0;
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
	ft_print_stacks(&lst_a1, &lst_b1);
	experimental_sort(&lst_a1, &lst_b1, 16);
	ft_print_stacks(&lst_a1, &lst_b1);
}
