/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 20:47:56 by azieniuk          #+#    #+#             */
/*   Updated: 2026/09/06 21:09:41 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	two_sort(t_data *data)
{
	sa(data);
}

static void	three_sort(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->stack_a->rank;
	b = data->stack_a->next->rank;
	c = data->stack_a->prev->rank;
	if (a > b && b < c && a < c)
		sa(data);
	else if (a > b && b > c)
		sa(data);
	else if (a > b && a > c)
		ra(data);
	else if (a < b && a > c)
		rra(data);
	else if (a < b && b > c)
	{
		rra(data);
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

	i = 0;
	assign_ranks(&data->stack_a, 5);
	while (i <= 1)
	{
		dir = find_shortest_path(&data->stack_a, i);
		while (data->stack_a->rank != i)
		{
			if (dir >= 0)
				ra(data);
			else
				rra(data);
		}
		pb(data);
		ft_print_stacks(1, &data->stack_a, &data->stack_b);
		i++;
	}
	three_sort(data);
	while (data->stack_b != NULL)
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
	else if (n == 5)
		five_sort(data);
}
