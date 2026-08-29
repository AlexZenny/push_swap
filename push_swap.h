/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:14:40 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/28 21:46:53 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	int				value;
	int				rank;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef enum e_mode
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}				t_mode;

typedef struct s_options
{
	t_mode	mode;
	int		mode_status;
	bool	bench;
}			  t_options;

typedef struct s_ops_counters
{
	int sa_count;
	int sb_count;
	int ss_count;
	int pa_count;
	int ra_count;
	int rb_count;
	int rr_count;
	int rra_count;
	int rrb_count;
	int rrr_count;
	int total_count;
}			t_ops_counters;

int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
void	ft_rotate(t_list **stack);
int		ra(t_list **stack_a);
int		rb(t_list **stack_a);
int		rr(t_list **stack_a, t_list **stack_b);
void	ft_rev_rotate(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
void	ft_addback(t_list **stack_a, int i);
void	ft_deallocate(t_list **stack_a);
int		ft_strncmp (const char *s1, const char *s2, size_t size);
long	ft_atol(const char *nptr);
int		ft_sqrt(int n);
int		ft_is_dublicate(t_list **stack_a, int value);
int		ft_is_number(char *str);
int 	ft_create_stack( int argc, char *argv[], t_list **stack_a);
int		ft_mode_status(t_options *options, t_mode mode);
int		ft_flags(const char *cursor, t_options *options);
int		input_parser(int argc, char *argv[], t_options *options);
float	calculate_disorder(t_list **stack);

void	simple_sort(t_list **stack_a, t_list **stack_b);
void	medium_sort(t_list **stack_a, t_list **stack_b, int n);
bool	is_sorted(t_list *stack_a);
int		find_min_position(t_list *stack_a);
int		rotation(t_list **stack_a, int min_position);
int		stack_len(t_list *stack_a);
void	assign_ranks(t_list **stack_a, int n);
int		find_shortest_path(t_list **stack, int target_rank);

void	ft_print_stacks(int fd, t_list **stack_a, t_list **stack_b);
#endif
