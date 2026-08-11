/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:33:55 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/11 19:36:58 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	swap(t_list **list)
{
	t_list	*temp;

	if ((!(*list)) || (!(*list)->next))
		return ;
	temp = *list;
	*list = (*list)->next;
	(*list)->next = temp;
}

void	swap_both(t_list **list_a, t_list **list_b)
{
	swap(list_a);
	swap(list_b);
}

#include <stdio.h>

int	main(void)
{
	t_list *list_a1 = malloc(sizeof(t_list));
	t_list *list_a2 = malloc(sizeof(t_list));

	list_a1->next = list_a2;
	list_a1->value = 1;
	list_a2->value = 2;

	printf("pre: a1 == %d, a2 == %d\n", list_a1->value, list_a2->value);
	swap(list_a);
	printf("aft: a1 == %d, a2 == %d\n", list_a1->value, list_a2->value);
}
