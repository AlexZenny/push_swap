/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:02:38 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/31 15:59:41 by tmalyshi         ###   ########.fr       */
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
	int		max_rank;

	max_rank = 1;
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

static void	radix_pass(t_data *data, int size, int bit_position)
{
	int	i;
	int	rank_value;

	i = 0;
	while (i < size)
	{
		rank_value = data->stack_a->rank;
		if (((rank_value >> bit_position) & 1) == 0)
			pb(data);
		else if (((rank_value >> bit_position) & 1) == 1)
			ra(data);
		i++;
	}
}

void	complex_sort(t_data *data)
{
	int	max_bits;
	int	size;
	int	bit_position;

	bit_position = 0;
	size = stack_len(data->stack_a);
	assign_ranks(&data->stack_a, size);
	max_bits = count_bits(find_largest_rank(data->stack_a));
	while (bit_position != max_bits)
	{
		radix_pass(data, size, bit_position);
		while (data->stack_b != NULL)
			pa(data);
		bit_position++;
	}
}
