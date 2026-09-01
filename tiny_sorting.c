/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 20:47:56 by azieniuk          #+#    #+#             */
/*   Updated: 2026/09/01 02:48:28 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	two_sort(t_data *data)
{
	sa(data);
}

static void	three_sort(t_data *data)
{
	if (data->stack_a->value > data->stack_a->next->value)
		sa(data);
	if (data->stack_a->value > data->stack_a->prev->value)
	{
		ra(data);
		sa(data);
		if (data->stack_a->next->value > data->stack_a->prev->value)
			sa(data);
	}
}

static void	four_sort(t_data *data)
{
	int	dir;

	assign_ranks(&data->stack_a, 4);
	dir = find_shortest_path(&data->stack_a, 0);
	while (data->stack_a->rank != 0)
	{
		if (dir >= 0)
			ra(data);
		else
			rra(data);
	}
	pb(data);
	three_sort(data);
	pa(data);
}

static void	five_sort(t_data *data)
{
	int	dir;
	int	i;

	i = -1;
	while (i++ <= 1)
	{
		assign_ranks(&data->stack_a, 5);
		dir = find_shortest_path(&data->stack_a, i);
		while (data->stack_a->rank != i)
		{
			if (dir >= 0)
				ra(data);
			else
				rra(data);
		}
		pb(data);
	}
	three_sort(data);
	pa(data);
	pa(data);
}

void	tiny_sort(t_data *data, int n)
{
	if (n == 2)
		two_sort(data);
	else if (n == 3)
		three_sort(data);
	else if (n == 4)
		four_sort(data);
	else
		five_sort(data);
}
