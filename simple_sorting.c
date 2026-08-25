/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 14:43:26 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/25 23:09:55 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int push_to_stack_b(t_list **stack_a, t_list **stack_b)
// {
//     push(stack_a, stack_b);
// }
int stack_len(t_list **stack_a)
{
    int len;
    t_list *current;
    t_list *head;

    len = 1;
    if (stack_a == NULL || *stack_a == NULL)
        return(-1);
    head = *stack_a;
    current = head;
    current = current->next;
    while(current != head)
    {
        len++;
        current = current->next;  
    }
    return(len);
} 
int rotation(t_list **stack_a, int min_position)
{
    int i;
    int len;

    i = 0;
    len = stack_len(stack_a);
    if (stack_a == NULL || *stack_a == NULL)
        return(-1);
    if (min_position <= len / 2)
        while (i != min_position)
        {
           ft_rotate(stack_a);
           i++; 
        }
    else 
        while(i < len - min_position)
        {
            ft_rev_rotate(stack_a);
            i++; 
        }
    return(i);
}
int find_min_position(t_list **stack_a)
{
    t_list  *current;
    t_list  *head;
    t_list  *min_value;
    int     position;
    int     min_position;

    min_position = 0;
    position = 1;
    if (stack_a == NULL || *stack_a == NULL)
        return(-1);
    head = *stack_a;
    current = head;
    min_value = current;
    current = current->next;
    while (current != head) 
    {
        if (min_value->value > current->value)
        {
            min_value = current;
            min_position = position;
        }
        current = current->next;
        position++;
    }
    return(min_position); 
}
void simple_sorting(t_list **stack_a, t_list **stack_b, t_options *opt)
{
t_list *first;
t_list *cursor;
int min_position;


first = *stack_a;
cursor = *stack_a;
cursor = cursor->next;
min_position = 0;
if (opt->mode == SIMPLE)
{
    while (*stack_a != NULL)
    {
        min_position = find_min_position(stack_a);
        rotation(stack_a, min_position);
        pb(stack_a, stack_b); 
    }
    while (*stack_b != NULL)
        pa(stack_b, stack_a);
}
}
