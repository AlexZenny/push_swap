/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 22:30:37 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/19 22:31:19 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

float	calculate_disorder(t_list **stack)
{
	float	all;
	float	sorted;
	t_list	*temp;

	if (!(*stack))
		return (NAN);
	all = 0.0;
	sorted = 0.0;
	temp = (*stack);
	while (temp != (*stack)->prev)
	{
		if (temp->value < temp->next->value)
			sorted++;
		all++;
		temp = temp->next;
	}
	return (all / sorted);
}

int	main(void)
{
	t_list *lst_a1 = malloc(sizeof(t_list));
	t_list *lst_a2 = malloc(sizeof(t_list));	
	t_list *lst_a3 = malloc(sizeof(t_list));
	t_list *lst_a4 = malloc(sizeof(t_list));	
	t_list *lst_a5 = malloc(sizeof(t_list));	

	lst_a1->next = lst_a2;
	lst_a1->prev = lst_a5;
	lst_a2->next = lst_a3;
	lst_a2->prev = lst_a1;	
	lst_a3->next = lst_a4;
	lst_a3->prev = lst_a2;
	lst_a4->next = lst_a5;
	lst_a4->prev = lst_a3;
	lst_a5->next = lst_a1;
	lst_a5->prev = lst_a4;
	lst_a1->value = 4;
	lst_a2->value = 2;	
	lst_a3->value = 3;
	lst_a4->value = 1;	
	lst_a5->value = 5;	

	printf("Disorder: %f\n", calculate_disorder(&lst_a1));
}
