/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 23:42:09 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/29 23:43:36 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_list **stack_a, t_list **stack_b, int n)
{
	float	dis;

	dis = calculate_disorder(stack_a);
	if (dis < 0.2)
		simple_sort(stack_a, stack_b);
	if (dis > 0.2 && dis < 0.5)
		medium_sort(stack_a, stack_b, n);
	if (dis > 0.5)
		ft_printf_fd(1, "Place complex sort here\n");
}

// int main(void)
// {
// 	t_list *lst_a1 = malloc(sizeof(t_list));
// 	t_list *lst_a2 = malloc(sizeof(t_list));
// 	t_list *lst_a3 = malloc(sizeof(t_list));
// 	t_list *lst_a4 = malloc(sizeof(t_list));
// 	t_list *lst_a5 = malloc(sizeof(t_list));
// 	t_list *lst_a6 = malloc(sizeof(t_list));
// 	t_list *lst_a7 = malloc(sizeof(t_list));
// 	t_list *lst_a8 = malloc(sizeof(t_list));
// 	t_list *lst_a9 = malloc(sizeof(t_list));
// 	t_list *lst_a10 = malloc(sizeof(t_list));
// 	t_list *lst_a11 = malloc(sizeof(t_list));
// 	t_list *lst_a12 = malloc(sizeof(t_list));
// 	t_list *lst_a13 = malloc(sizeof(t_list));
// 	t_list *lst_a14 = malloc(sizeof(t_list));
// 	t_list *lst_a15 = malloc(sizeof(t_list));
// 	t_list *lst_a16 = malloc(sizeof(t_list));
// 	t_list *lst_a17 = malloc(sizeof(t_list));
// 	t_list *lst_a18 = malloc(sizeof(t_list));
// 	t_list *lst_b1 = NULL;
// 	lst_a1->next = lst_a2;
// 	lst_a1->prev = lst_a18;
// 	lst_a2->next = lst_a3;
// 	lst_a2->prev = lst_a1;
// 	lst_a3->next = lst_a4;
// 	lst_a3->prev = lst_a2;
// 	lst_a4->next = lst_a5;
// 	lst_a4->prev = lst_a3;
// 	lst_a5->next = lst_a6;
// 	lst_a5->prev = lst_a4;
// 	lst_a6->next = lst_a7;
// 	lst_a6->prev = lst_a5;
// 	lst_a7->next = lst_a8;
// 	lst_a7->prev = lst_a6;
// 	lst_a8->next = lst_a9;
// 	lst_a8->prev = lst_a7;
// 	lst_a9->next = lst_a10;
// 	lst_a9->prev = lst_a8;
// 	lst_a10->next = lst_a11;
// 	lst_a10->prev = lst_a9;
// 	lst_a11->next = lst_a12;
// 	lst_a11->prev = lst_a10;
// 	lst_a12->next = lst_a13;
// 	lst_a12->prev = lst_a11;
// 	lst_a13->next = lst_a14;
// 	lst_a13->prev = lst_a12;
// 	lst_a14->next = lst_a15;
// 	lst_a14->prev = lst_a13;
// 	lst_a15->next = lst_a16;
// 	lst_a15->prev = lst_a14;
// 	lst_a16->next = lst_a17;
// 	lst_a16->prev = lst_a15;
// 	lst_a17->next = lst_a18;
// 	lst_a17->prev = lst_a16;
// 	lst_a18->next = lst_a1;
// 	lst_a18->prev = lst_a17;
// 	lst_a1->value = 42;
// 	lst_a2->value = -7;
// 	lst_a3->value = 19;
// 	lst_a4->value = 83;
// 	lst_a5->value = 4;
// 	lst_a6->value = 56;
// 	lst_a7->value = -21;
// 	lst_a8->value = 31;
// 	lst_a9->value = 72;
// 	lst_a10->value = 5;
// 	lst_a11->value = 14;
// 	lst_a12->value = 91;
// 	lst_a13->value = -3;
// 	lst_a14->value = 27;
// 	lst_a15->value = 68;
// 	lst_a16->value = 11;
// 	lst_a17->value = 48;
// 	lst_a18->value = 0;
//
// 	// lst_a1->value = 17;
// 	// lst_a2->value = 16;
// 	// lst_a3->value = 15;
// 	// lst_a4->value = 14;
// 	// lst_a5->value = 13;
// 	// lst_a6->value = 12;
// 	// lst_a7->value = 11;
// 	// lst_a8->value = 10;
// 	// lst_a9->value = 9;
// 	// lst_a10->value = 6;
// 	// lst_a11->value = 7;
// 	// lst_a12->value = 8;
// 	// lst_a13->value = 5;
// 	// lst_a14->value = 4;
// 	// lst_a15->value = 3;
// 	// lst_a16->value = 2;
// 	// lst_a17->value = 1;
// 	// lst_a18->value = 0;
//
// 	// lst_a1->value = 3;
// 	// lst_a2->value = 1;
// 	// lst_a3->value = 2;
// 	// lst_a4->value = 0;
// 	// lst_a5->value = 4;
// 	// lst_a6->value = 5;
// 	// lst_a7->value = 6;
// 	// lst_a8->value = 7;
// 	// lst_a9->value = 8;
// 	// lst_a10->value = 9;
// 	// lst_a11->value = 10;
// 	// lst_a12->value = 11;
// 	// lst_a13->value = 12;
// 	// lst_a14->value = 13;
// 	// lst_a15->value = 14;
// 	// lst_a16->value = 15;
// 	// lst_a17->value = 16;
// 	// lst_a18->value = 17;
// 	adaptive_sort(&lst_a1, &lst_b1, 18);
// }
