/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:14:40 by azieniuk          #+#    #+#             */
/*   Updated: 2026/09/07 17:17:22 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <math.h>
# include <stdbool.h>
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

int		count_bits(int max_rank);
int		find_largest_rank(t_list *stack_a);
void	complex_sort(t_data *data);
float	calculate_disorder(t_list **stack);
int		*find_chunk_sizes(int n, int c_count);
int		pb_chunk(t_data *data, int c_size, int n);
void	extract_chunk(t_data *data, int c_size, int *max_rank);
void	medium_sort(t_data *data, int n);
void	assign_ranks(t_list **stack_a, int n);
int		find_shortest_path(t_list **stack, int target_rank);
int		stack_len(t_list *stack_a);
int		rotation(t_data *data, int min_position);
int		find_min_position(t_list *stack_a);
bool	is_sorted(t_list **stack_a);
void	simple_sort(t_data *data);
void	adaptive_sort(t_data *data, float dis);
void	tiny_sort(t_data *data, int n);
int		pa(t_data *data);
int		pb(t_data *data);
void	ft_rev_rotate(t_list **stack);
int		rra(t_data *data);
int		rrb(t_data *data);
int		rrr(t_data *data);
void	ft_rotate(t_list **stack);
int		ra(t_data *data);
int		rb(t_data *data);
int		rr(t_data *data);
int		sa(t_data *data);
int		sb(t_data *data);
int		ss(t_data *data);
int		parse_tokens(const char *arg, bool multiple_tokens, t_list **stack_a);
int		parse_arg(const char *arg, t_list **stack_a);
int		parse_input(char **argv, t_data *data);
int		count_tokens(char const *arg);
void	count_token_lens(char const *arg, int *lens);
void	fill_sub(char const *arg, char *sub, int *idx);
char	**allocate_subs(int count, int *lens);
char	**split_arg(char const *arg);
int		check_for_duplicates(t_list **stack_a, int value);
void	lst_add_back(t_list **stack_a, t_list *new);
int		lst_add_new(const char *token, t_list **stack_a);
void	ft_deallocate(t_list **stack_a);
void	print_complexity(float dis);
void	benchmark_mode(t_data *data, float dis);
int		ft_sqrt(int n);
int		count_stack_members(t_list **stack);
long	ft_atol(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t size);
int		is_num(char c);
int		is_whitespace(char c);
int		is_minus(char c);
void	initialize_counters(t_data *data);
void	initialize_data(t_data *data);
int		set_algorithm(t_options *opt, t_mode mode);
int		check_flags(char *arg, t_options *opt);
int		error(t_data *data);
#endif
