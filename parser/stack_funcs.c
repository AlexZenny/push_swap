/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 03:45:48 by azieniuk          #+#    #+#             */
/*   Updated: 2026/09/06 18:38:31 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_duplicates(t_list **stack_a, int value)
{
	t_list	*temp;

	temp = (*stack_a)->next;
	if (*stack_a == NULL || stack_a == NULL)
		return (0);
	while (temp != *stack_a)
	{
		if (temp->value == value)
			return (1);
		temp = temp->next;
	}
	if (temp->value == value)
		return (1);
	return (0);
}

void	lst_add_back(t_list **stack_a, t_list *new)
{
	t_list	*last;

	last = (*stack_a)->prev;
	last->next = new;
	new->prev = last;
	new->next = *stack_a;
	(*stack_a)->prev = new;
}

int	lst_add_new(const char *token, t_list **stack_a)
{
	t_list	*new;

	if (!token)
		return (1);
	new = malloc(sizeof(t_list));
	if (!new)
		return (1);
	new->value = ft_atol(token);
	if (*stack_a)
	{
		if (check_for_duplicates(stack_a, new->value))
		{
			free(new);
			return (1);
		}
		lst_add_back(stack_a, new);
	}
	else
	{
		new->next = new;
		new->prev = new;
		*stack_a = new;
	}
	return (0);
}

void	ft_deallocate(t_list **stack_a)
{
	t_list	*curr;
	t_list	*next;
	t_list	*first;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	first = *stack_a;
	curr = first->next;
	while (curr != first)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(first);
	*stack_a = NULL;
}
