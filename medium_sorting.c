/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 21:15:21 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/31 16:05:02 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*find_chunk_sizes(int n, int c_count)
{
	int	*c_sizes;
	int	rem;
	int	i;

	c_sizes = malloc(sizeof(int) * c_count);
	if (!c_sizes)
		return (NULL);
	rem = n - c_count * c_count;
	i = 0;
	while (i < c_count)
	{
		c_sizes[i] = c_count;
		if (rem-- > 0)
			c_sizes[i]++;
		i++;
	}
	return (c_sizes);
}

int	pb_chunk(t_data *data, int c_size, int n)
{
	static int	max_rank = -1;

	max_rank += c_size;
	while (n-- && c_size)
	{
		if (data->stack_a->rank <= max_rank)
		{
			pb(data);
			c_size--;
		}
		else
			ra(data);
	}
	return (max_rank);
}

void	extract_chunk(t_data *data, int c_size, int *max_rank)
{
	int	dir;

	while (c_size > 0)
	{
		dir = find_shortest_path(&data->stack_b, *max_rank);
		while (data->stack_b->rank != (*max_rank))
		{
			if (dir >= 0)
				rb(data);
			else
				rrb(data);
		}
		pa(data);
		(*max_rank)--;
		c_size--;
	}
}

void	medium_sort(t_data *data, int n)
{
	int	max_rank;
	int	*c_sizes;
	int	c_count;
	int	i;

	assign_ranks(&data->stack_a, n);
	c_count = ft_sqrt(n);
	c_sizes = find_chunk_sizes(n, c_count);
	i = 0;
	while (i < c_count)
		max_rank = pb_chunk(data, c_sizes[i++], n);
	while (i--)
		extract_chunk(data, c_sizes[i], &max_rank);
	free(c_sizes);
}
