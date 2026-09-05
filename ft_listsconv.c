/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 14:04:16 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/09/02 11:42:31 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_addback(t_list **stack_a, int i)
{
	t_list	*curr;
	t_list	*temp;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = new_node;
	new_node->prev = new_node;
	new_node->value = i;
	if (*stack_a == NULL)
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

void	ft_deallocate(t_list **stack_a)
{
	t_list	*curr;
	t_list	*next;
	t_list	*first;

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

int	ft_is_dublicate(t_list **stack_a, int value)
{
	t_list	*curr;
	t_list	*head;

	head = *stack_a;
	curr = head;
	if (*stack_a == NULL || stack_a == NULL)
		return (0);
	while (1)
	{
		if (curr->value == value)
			return (1);
		curr = curr->next;
		if (curr == head)
			break ;
	}
	return (0);
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_create_stack(int **arr, int n, t_list **stack_a)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (ft_is_dublicate(stack_a, *arr[i]) || *arr[i] > INT_MAX || *arr[i] < INT_MIN)
			return (1);
		ft_addback(stack_a, *arr[i++]);
	}
	return (0);
}

// int	ft_create_stack(int argc, char *argv[], t_list **stack_a)
// {
// 	long	value;
// 	int		i;
//
// 	i = 1;
// 	while (i < argc)
// 	{
// 		if (argv[i][0] == '-' && argv[i][1] == '-')
// 		{
// 			i++;
// 			continue ;
// 		}
// 		value = ft_atol(argv[i]);
// 		if (value > INT_MAX || value < INT_MIN)
// 			return (1);
// 		if (ft_is_dublicate(stack_a, value) == 1)
// 			return (1);
// 		ft_addback(stack_a, (int)value);
// 		i++;
// 	}
// 	return (0);
// }
