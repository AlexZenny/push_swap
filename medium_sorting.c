/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 21:15:21 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/29 21:20:57 by azieniuk         ###   ########.fr       */
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

int	pb_chunk(t_list **st_a, t_list **st_b, int c_size, int n)
{
	static int	max_rank = -1;

	max_rank += c_size;
	while (n-- && c_size)
	{
		if ((*st_a)->rank <= max_rank)
		{
			pb(st_a, st_b);
			c_size--;
		}
		else
			ra(st_a);
	}
	return (max_rank);
}

void	extract_chunk(t_list **st_a, t_list **st_b, int c_size, int *max_rank)
{
	int		dir;

	while (c_size > 0)
	{
		dir = find_shortest_path(st_b, *max_rank);
		while ((*st_b)->rank != (*max_rank))
		{
			if (dir >= 0)
				rb(st_b);
			else
				rrb(st_b);
		}
		pa(st_a, st_b);
		(*max_rank)--;
		c_size--;
	}
}

void	medium_sort(t_list **stack_a, t_list **stack_b, int n)
{
	int	max_rank;
	int	*c_sizes;
	int	c_count;
	int	i;

	assign_ranks(stack_a, n);
	c_count = ft_sqrt(n);
	c_sizes = find_chunk_sizes(n, c_count);
	i = 0;
	while (i < c_count)
		max_rank = pb_chunk(stack_a, stack_b, c_sizes[i++], n);
	while (i--)
		extract_chunk(stack_a, stack_b, c_sizes[i], &max_rank);
}

// int main(void)
// {
// 	t_list *lst_a1 = malloc(sizeof(t_list));
// 	t_list *lst_a2 = malloc(sizeof(t_list));
// 	t_list *lst_a3 = malloc(sizeof(t_list));
// 	t_list *lst_a4 = malloc(sizeof(t_list));
// 	t_list *lst_a5 = malloc(sizeof(t_list));
// 	t_list *lst_a6 = malloc(sizeof(t_list));
// 	t_list *lst_a7 = malloc(sizeof(t_list));
// 	t_list *lst_a8 = malloc(sizeof(t_list));
// 	t_list *lst_a9 = malloc(sizeof(t_list));
// 	t_list *lst_a10 = malloc(sizeof(t_list));
// 	t_list *lst_a11 = malloc(sizeof(t_list));
// 	t_list *lst_a12 = malloc(sizeof(t_list));
// 	t_list *lst_a13 = malloc(sizeof(t_list));
// 	t_list *lst_a14 = malloc(sizeof(t_list));
// 	t_list *lst_a15 = malloc(sizeof(t_list));
// 	t_list *lst_a16 = malloc(sizeof(t_list));
// 	t_list *lst_a17 = malloc(sizeof(t_list));
// 	t_list *lst_a18 = malloc(sizeof(t_list));
// 	t_list *lst_b1 = NULL;
// 	lst_a1->next = lst_a2;
// 	lst_a1->prev = lst_a18;
// 	lst_a2->next = lst_a3;
// 	lst_a2->prev = lst_a1;
// 	lst_a3->next = lst_a4;
// 	lst_a3->prev = lst_a2;
// 	lst_a4->next = lst_a5;
// 	lst_a4->prev = lst_a3;
// 	lst_a5->next = lst_a6;
// 	lst_a5->prev = lst_a4;
// 	lst_a6->next = lst_a7;
// 	lst_a6->prev = lst_a5;
// 	lst_a7->next = lst_a8;
// 	lst_a7->prev = lst_a6;
// 	lst_a8->next = lst_a9;
// 	lst_a8->prev = lst_a7;
// 	lst_a9->next = lst_a10;
// 	lst_a9->prev = lst_a8;
// 	lst_a10->next = lst_a11;
// 	lst_a10->prev = lst_a9;
// 	lst_a11->next = lst_a12;
// 	lst_a11->prev = lst_a10;
// 	lst_a12->next = lst_a13;
// 	lst_a12->prev = lst_a11;
// 	lst_a13->next = lst_a14;
// 	lst_a13->prev = lst_a12;
// 	lst_a14->next = lst_a15;
// 	lst_a14->prev = lst_a13;
// 	lst_a15->next = lst_a16;
// 	lst_a15->prev = lst_a14;
// 	lst_a16->next = lst_a17;
// 	lst_a16->prev = lst_a15;
// 	lst_a17->next = lst_a18;
// 	lst_a17->prev = lst_a16;
// 	lst_a18->next = lst_a1;
// 	lst_a18->prev = lst_a17;
// 	lst_a1->value = 42;
// 	lst_a2->value = -7;
// 	lst_a3->value = 19;
// 	lst_a4->value = 83;
// 	lst_a5->value = 4;
// 	lst_a6->value = 56;
// 	lst_a7->value = -21;
// 	lst_a8->value = 31;
// 	lst_a9->value = 72;
// 	lst_a10->value = 5;
// 	lst_a11->value = 14;
// 	lst_a12->value = 91;
// 	lst_a13->value = -3;
// 	lst_a14->value = 27;
// 	lst_a15->value = 68;
// 	lst_a16->value = 11;
// 	lst_a17->value = 48;
// 	lst_a18->value = 0;
// 	ft_print_stacks(1, &lst_a1, &lst_b1);
// 	medium_sort(&lst_a1, &lst_b1, 18);
// 	ft_print_stacks(1, &lst_a1, &lst_b1);
// }
