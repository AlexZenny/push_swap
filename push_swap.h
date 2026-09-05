/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:14:40 by azieniuk          #+#    #+#             */
/*   Updated: 2026/09/02 11:03:01 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

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
}					t_mode;

typedef struct s_options
{
	t_mode			mode;
	int				mode_status;
	bool			bench;
}					t_options;

typedef struct s_ops_counters
{
	int				sa_count;
	int				sb_count;
	int				ss_count;
	int				pa_count;
	int				pb_count;
	int				ra_count;
	int				rb_count;
	int				rr_count;
	int				rra_count;
	int				rrb_count;
	int				rrr_count;
	int				total_count;
}					t_ops_counters;

typedef struct s_data
{
	t_options		options;
	t_list			*stack_a;
	t_list			*stack_b;
	t_ops_counters	ops;
}					t_data;

int					pa(t_data *data);
int					pb(t_data *data);
int					sa(t_data *data);
int					sb(t_data *data);
int					ss(t_data *data);
void				ft_rotate(t_list **stack);
int					ra(t_data *data);
int					rb(t_data *data);
int					rr(t_data *data);
void				ft_rev_rotate(t_list **stack);
int					rra(t_data *data);
int					rrb(t_data *data);
int					rrr(t_data *data);
void				ft_addback(t_list **stack_a, int i);
void				ft_deallocate(t_list **stack_a);
int					ft_strncmp(const char *s1, const char *s2, size_t size);
long				ft_atol(const char *nptr);
int					ft_sqrt(int n);
int					ft_is_dublicate(t_list **stack_a, int value);
int					ft_is_number(char *str);
int					ft_create_stack(int **arr, int n, t_list **stack_a);
int					ft_mode_status(t_options *options, t_mode mode);
int					ft_flags(const char *cursor, t_options *options);
int					input_parser(int argc, char **argv, int **arr, t_options *options);
void				initialize_data(t_data *data);
void				initialize_counters(t_data *data);
float				calculate_disorder(t_list **stack);
int					count_stack_members(t_list **stack);

void				select_sort(t_data *data, float disorder);
void				tiny_sort(t_data *data, int n);
void				simple_sort(t_data *data);
void				medium_sort(t_data *data, int n);
void				complex_sort(t_data *data);

bool				is_sorted(t_list **stack_a);
int					find_min_position(t_list *stack_a);
int					rotation(t_data *data, int min_position);
int					stack_len(t_list *stack_a);
void				assign_ranks(t_list **stack_a, int n);
int					find_shortest_path(t_list **stack, int target_rank);
int					find_largest_rank(t_list *stack_a);
int					count_bits(int max_rank);
void				benchmark_mode(t_data *data, float dis);
char				**ft_split(char const *s, char c);
void				ft_print_stacks(int fd, t_list **stack_a, t_list **stack_b);
#endif
