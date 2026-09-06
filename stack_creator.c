/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 03:45:48 by azieniuk          #+#    #+#             */
/*   Updated: 2026/09/06 03:45:48 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_duplicates(t_list **stack_a, int value)
{
	t_list	*temp;

	temp = (*stack_a)->next;
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
	t_list  *last;

	last = (*stack_a)->prev;

	last->next = new;
	new->prev = last;
	new->next = *stack_a;
	(*stack_a)->prev = new;
}

int	lst_add_new(const char *token, t_list **stack_a)
{
	t_list  *new;

	new = malloc(sizeof(t_list));
	if (!new || !token)
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
