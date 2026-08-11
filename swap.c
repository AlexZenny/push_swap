/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:33:55 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/11 23:25:00 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	t_list	*temp;

	if ((!(*list)) || (!(*list)->next))
		return ;
	temp = (*list)->next;
	(*list)->next = temp->next;
	temp->next = *list;
	*list = temp;
}

void	swap_both(t_list **list_a, t_list **list_b)
{
	swap(list_a);
	swap(list_b);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	t_list *list_a1 = malloc(sizeof(t_list));
// 	t_list *list_a2 = malloc(sizeof(t_list));	
// 	t_list *list_b1 = malloc(sizeof(t_list));
// 	t_list *list_b2 = malloc(sizeof(t_list));
//
// 	list_a1->next = list_a2;
// 	list_a1->value = 1;
// 	list_a2->value = 2;	
// 	list_b1->next = list_b2;
// 	list_b1->value = 1;
// 	list_b2->value = 2;
//
// 		printf("pre: a1 == %d, a2 == %d\n", list_a1->value, list_a1->next->value);
// 		printf("pre: b1 == %d, b2 == %d\n", list_b1->value, list_b1->next->value);
// 		swap_both(&list_a1, &list_b1);
// 		printf("aft: a1 == %d, a2 == %d\n", list_a1->value, list_a1->next->value);
// 		printf("pre: b1 == %d, b2 == %d\n", list_b1->value, list_b1->next->value);
// }
