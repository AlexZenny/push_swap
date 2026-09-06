/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sorting_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 05:32:47 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/29 05:32:47 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_ranks(t_list **stack_a, int n)
{
	t_list	*temp;
	t_list	*cur;
	int		i;
	int		k;

	i = 0;
	temp = (*stack_a);
	while (i++ < n)
	{
		k = 0;
		cur = temp;
		cur->rank = 0;
		while (k++ < n)
		{
			temp = temp->next;
			if (cur->value > temp->value)
				cur->rank++;
		}
		temp = temp->next;
	}
}

int	find_shortest_path(t_list **stack, int target_rank)
{
	t_list	*temp;
	int		forw_moves;
	int		back_moves;

	temp = *stack;
	forw_moves = 0;
	while (temp->rank != target_rank)
	{
		temp = temp->next;
		forw_moves++;
	}
	temp = *stack;
	back_moves = 0;
	while (temp->rank != target_rank)
	{
		temp = temp->prev;
		back_moves--;
	}
	if (forw_moves <= back_moves * -1)
		return (forw_moves);
	return (back_moves);
}
