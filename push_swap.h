/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:14:40 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/17 19:31:33 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>

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
	bool	bench;
}			  t_options;

void	ft_rotate(t_list **stack);
void	ft_rotate_both(t_list **stack_a, t_list **stack_b);
void	ft_addback(t_list **stack_a, int i);
void	ft_deallocate(t_list **stack_a);
int		ft_strncmp (const char *s1, const char *s2, size_t size);

#endif
