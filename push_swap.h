/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:14:40 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/24 13:52:39 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
#include <limits.h>

typedef struct s_list
{
	int				value;
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
void	ft_rotate_both(t_list **stack_a, t_list **stack_b);
void	ft_rev_rotate(t_list **stack);
void	ft_rev_rotate_both(t_list **stack_a, t_list **stack_b);
void	ft_addback(t_list **stack_a, int i);
void	ft_deallocate(t_list **stack_a);
int		ft_strncmp (const char *s1, const char *s2, size_t size);
long	ft_atol(const char *nptr);
int		ft_is_dublicate(t_list **stack_a, int value);
int		ft_is_number(char *str);
int 	ft_create_stack( int argc, char *argv[], t_list **stack_a);
int		ft_mode_status(t_options *options, t_mode mode);
int		ft_flags(const char *cursor, t_options *options);
int		input_parser(int argc, char *argv[], t_options *options);
float	calculate_disorder(t_list **stack);

#endif
