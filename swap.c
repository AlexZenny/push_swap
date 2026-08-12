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

void	swap(t_list **lst)
{
	t_list	*temp;

	if ((!(*lst)) || (!(*lst)->next))
		return ;
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = *lst;
	*lst = temp;
}

void	swap_both(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a);
	swap(lst_b);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	t_list *lst_a1 = malloc(sizeof(t_list));
// 	t_list *lst_a2 = malloc(sizeof(t_list));	
// 	t_list *lst_b1 = malloc(sizeof(t_list));
// 	t_list *lst_b2 = malloc(sizeof(t_list));
//
// 	lst_a1->next = lst_a2;
// 	lst_a1->value = 1;
// 	lst_a2->value = 2;	
// 	lst_b1->next = lst_b2;
// 	lst_b1->value = 1;
// 	lst_b2->value = 2;
//
// 		printf("pre: a1 == %d, a2 == %d\n", lst_a1->value, lst_a1->next->value);
// 		printf("pre: b1 == %d, b2 == %d\n", lst_b1->value, lst_b1->next->value);
// 		swap_both(&lst_a1, &lst_b1);
// 		printf("aft: a1 == %d, a2 == %d\n", lst_a1->value, lst_a1->next->value);
// 		printf("pre: b1 == %d, b2 == %d\n", lst_b1->value, lst_b1->next->value);
// }
