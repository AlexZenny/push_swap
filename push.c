/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:33:50 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/11 19:33:50 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **list_a, **list_b)
{
	if ((!(*list_a)) || (!(*list_b)))
		return ;
	(*list_b)->prev->next = *list_a;
	(*list_b)->prev = *list_a;
	(*list_a)->prev->next = (*list_a)->next;
	(*list_a)->next->prev = (*list_a)->prev;
	(*list_a)->next = *list_b;
	(*list_a)->prev = (*list_b)->prev;
}
