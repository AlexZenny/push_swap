/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 14:04:16 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/17 11:32:58 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void ft_addback(t_list **stack_a, int i)
{
	t_list *curr;
	t_list *temp;
	
	t_list *new_node = malloc(sizeof(t_list));
	if(new_node == NULL)
		return ;
	new_node->next = new_node;
	new_node->prev = new_node;
	new_node->value = i;
	if(*stack_a == NULL)
	{
		*stack_a = new_node;
		return ;
	}	
	curr = *stack_a;
	temp = *stack_a;
	while (curr->next != temp)
	{
		curr = curr->next;
	}
	curr->next = new_node;
	new_node->prev = curr;
	new_node->next = temp;
	temp->prev = new_node;
}
void ft_deallocate(t_list **stack_a)
{
	t_list *curr;
	t_list *next;
	t_list *first;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	first = *stack_a;
	curr = first->next;
	while (curr != first)
	{
		next = curr->next;
		free(curr);
		curr = next;

	}
	free(first);
	*stack_a = NULL;
}
// int	main(void)
// {
// 	t_list	*temp;
// 	t_list *stack_a;
// 	int i[] = {3, 5, 7, 8};
// 	int j;
// 	int arr_size;

// 	arr_size = sizeof(i)/sizeof(i[0]);
// 	stack_a = NULL;
// 	j = 0;
// 	while (j < arr_size)
// 	{
// 		ft_addback( &stack_a, i[j]);
// 		j++;
// 	}
// 	temp = stack_a;
// 	j = 0;
// 	while (j < arr_size)
// 		{
// 			printf("%d\n", temp->value);
// 			temp = temp->next;
// 			j++;
// 		}
// 	ft_deallocate(&stack_a);
// 	return(0);
// }