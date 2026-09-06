/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 22:30:37 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/20 17:28:48 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	calculate_disorder(t_list **stack)
{
	float	all;
	float	unsorted;
	t_list	*temp;

	if (!(*stack))
		return (NAN);
	all = 0.0;
	unsorted = 0.0;
	temp = (*stack);
	while (temp != (*stack)->prev)
	{
		if (temp->value > temp->next->value)
			unsorted++;
		all++;
		temp = temp->next;
	}
	return (unsorted / all);
}
