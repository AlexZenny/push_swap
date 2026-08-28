/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg_medium.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 21:15:21 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/27 15:34:14 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_ranks(t_list **stack_a, int n)
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

static int	*find_chunk_sizes(int n, int c_count)
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
		ft_printf_fd(1, "%d ", c_sizes[i]);
		i++;
	}
	return (c_sizes);
}

static void	push_chunk_b(t_list **stack_a, t_list **stack_b, int c_size, int n)
{
	static int	max_rank = -1;

	max_rank += c_size;
	while (n-- && c_size)
	{
		if ((*stack_a)->rank <= max_rank)
		{
			pb(stack_a, stack_b);
			ft_print_stacks(1, stack_a, stack_b);
			c_size--;
		}
		else
		{
			ra(stack_a);
			ft_print_stacks(1, stack_a, stack_b);
		}
	}
}

static void	sort_chunk_in_b(t_list **stack_a, t_list **stack_b, int c_size, int max_rank)
{
	bool	reverse;

	reverse = false;
	while (c_size > 0)
	{
		while ((*stack_b)->rank != max_rank)
		{
			if (!reverse)
				rb(stack_b);
			else
				rrb(stack_b);
		ft_print_stacks(1, stack_a, stack_b);
		}
		pa(stack_a, stack_b);
		ft_print_stacks(1, stack_a, stack_b);
		reverse = !reverse;
		max_rank--;
		c_size--;
	}
}

void	medium_sort(t_list **stack_a, t_list **stack_b, int n)
{
	int		*c_sizes;
	int		c_count;
	int		i;
	int		k;
	int		m;

	assign_ranks(stack_a, n);
	c_count = ft_sqrt(n);
	c_sizes = find_chunk_sizes(n, c_count);
	i = 0;
	k = 0;
	ft_print_stacks(1, stack_a, stack_b);
	while (k++ < c_count)
		push_chunk_b(stack_a, stack_b, c_sizes[i++], n);
	k = 0;
	m = n - 1;
	while (k++ <= c_count)
	{
		sort_chunk_in_b(stack_a, stack_b, c_sizes[i], m);
		m -= c_sizes[i];
		i--;
	}
}

int main(void)
{
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
	t_list *lst_a17 = malloc(sizeof(t_list));
	t_list *lst_a18 = malloc(sizeof(t_list));
	t_list *lst_b1 = NULL;
	lst_a1->next = lst_a2;
	lst_a1->prev = lst_a18;
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
	lst_a16->next = lst_a17;
	lst_a16->prev = lst_a15;
	lst_a17->next = lst_a18;
	lst_a17->prev = lst_a16;
	lst_a18->next = lst_a1;
	lst_a18->prev = lst_a17;
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
	lst_a17->value = 48;
	lst_a18->value = 0;
	medium_sort(&lst_a1, &lst_b1, 18);
	ft_print_stacks(1, &lst_a1, &lst_b1);
}
