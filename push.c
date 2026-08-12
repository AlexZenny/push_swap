/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:33:50 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/12 13:37:31 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **lst_from, t_list **lst_to)
{
	t_list	*temp;

	if ((!(*lst_from)) || (!(*lst_to)))
		return ;
	temp = *lst_from;
	*lst_from = temp->next;
	(*lst_from)->prev = temp->prev;
	temp->prev->next = *lst_from;
	temp->next = *lst_to;
	temp->prev = (*lst_to)->prev;
	(*lst_to)->prev->next = temp;
	(*lst_to)->prev = temp;
	*lst_to = temp;
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	t_list *lst_a1 = malloc(sizeof(t_list));
// 	t_list *lst_a2 = malloc(sizeof(t_list));	
// 	t_list *lst_a3 = malloc(sizeof(t_list));	
// 	t_list *lst_b1 = malloc(sizeof(t_list));
// 	t_list *lst_b2 = malloc(sizeof(t_list));
// 	t_list *lst_b3 = malloc(sizeof(t_list));
//
// 	lst_a1->next = lst_a2;
// 	lst_a1->prev = lst_a3;
// 	lst_a2->next = lst_a3;
// 	lst_a2->prev = lst_a1;	
// 	lst_a3->next = lst_a1;
// 	lst_a3->prev = lst_a2;
// 	lst_a1->value = 1;
// 	lst_a2->value = 2;	
// 	lst_a3->value = 3;	
// 	lst_b1->next = lst_b2;
// 	lst_b1->prev = lst_b3;
// 	lst_b2->next = lst_b3;
// 	lst_b2->prev = lst_b1;	
// 	lst_b3->next = lst_b1;
// 	lst_b3->prev = lst_b2;
// 	lst_b1->value = 4;
// 	lst_b2->value = 5;
// 	lst_b3->value = 6;
//
// 	printf("pre: a1 == %d, a2 == %d, a3 == %d\n", lst_a1->value, 
// 			lst_a1->next->value, lst_a1->next->next->value);
// 	printf("pre: b1 == %d, b2 == %d, b3 == %d\n", lst_b1->value, 
// 			lst_b1->next->value, lst_b1->next->next->value);
// 	push(&lst_a1, &lst_b1);
// 	printf("pre: a1 == %d, a2 == %d, a3 == %d\n", lst_a1->value,
// 			lst_a1->next->value, lst_a1->next->next->value);
// 	printf("pre: b1 == %d, b2 == %d, b3 == %d\n", lst_b1->value,
// 			lst_b1->next->value, lst_b1->next->next->value);
// }
