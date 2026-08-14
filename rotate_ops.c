/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:46:05 by tmalyshi          #+#    #+#             */
/*   Updated: 2026/08/14 15:21:55 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*temp;

	if (stack == NULL || *stack == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = temp;
}
void	ft_rotate_both(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL || 
		stack_b == NULL || *stack_b == NULL)
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

int	main(void)
{
	//t_list	*temp;
	t_list *stack_a;
	int i[] = {3, 5, 7, 8};
	int j;
	int arr_size;

	arr_size = sizeof(i)/sizeof(i[0]);
	stack_a = NULL;
	j = 0;
	while (j < arr_size)
	{
		ft_addback( &stack_a, i[j]);
		j++;
	}
	//temp = stack_a;
	j = 0;
	// while (j < arr_size)
	// 	{
	// 		printf("%d\n", temp->value);
	// 		temp = temp->next;
	// 		j++;
	// 	}


	ft_rotate(&stack_a);
	
	j = 0;
	while (j < arr_size)
		{
			printf("%d\n", stack_a->value);
			stack_a = stack_a->next;
			j++;
		}

	ft_deallocate(&stack_a);
	return(0);
}


