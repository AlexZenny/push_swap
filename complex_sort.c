/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:02:38 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/30 17:38:31 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_bits(int max_rank)
{
	int	count_bits;

	count_bits = 0;
	while (max_rank != 0)
	{
		max_rank = max_rank >> 1;
		count_bits++;
	}
	return (count_bits);
}
int	find_largest_rank(t_list *stack_a)
{
	t_list	*current;
	t_list	*head;
	t_list	*max_rank_node;
	int		position;
	int		max_rank;

	max_rank = 0;
	position = 1;
	if (stack_a == NULL)
		return (-1);
	head = stack_a;
	current = head;
	max_rank_node = current;
	current = current->next;
	while (current != head)
	{
		if (max_rank_node->rank < current->rank)
			max_rank_node = current;
		current = current->next;
	}
	max_rank = max_rank_node->rank;
	return (max_rank);
}

void	complex_sort(t_list **stack_a, t_list **stack_b)
{
	int	bit_position;
	int	i;
	int	rank_value;
	int	size;

	bit_position = 0;
	i = 0;
	assign_ranks(stack_a, stack_len(*stack_a));
	size = (find_largest_rank(*stack_a) + 1);
	while (bit_position != (count_bits - 1))
	{
		rank_value = (*stack_a)->rank;
		while (i <= size)
		{
			if (((rank_value >> bit_position) & 1) == 0)
				pb(stack_a, stack_b);
			else if (((rank_value >> bit_position) & 1) == 1)
				ra(stack_a);
			i++;
		}
		while (stack_b != NULL)
			pa(stack_a, stack_b);
		bit_position++;
	}
}
