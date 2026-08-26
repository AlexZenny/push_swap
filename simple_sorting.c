/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 14:43:26 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/26 20:13:54 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_len(t_list *stack_a)
{
    int len;
    t_list *current;
    t_list *head;

    len = 1;
    if (stack_a == NULL)
        return(0);
    head = stack_a;
    current = head;
    current = current->next;
    while(current != head)
    {
        current = current->next;
        len++;
        }
    return(len);
} 
int rotation(t_list **stack_a, int min_position)
{
    int i;
    int len;

    i = 0;
    if (stack_a == NULL || *stack_a == NULL)
        return(-1);
    len = stack_len(*stack_a);
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
int find_min_position(t_list *stack_a)
{
    t_list  *current;
    t_list  *head;
    t_list  *min_value;
    int     position;
    int     min_position;

    min_position = 0;
    position = 1;
    if (stack_a == NULL)
        return(-1);
    head = stack_a;
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
bool is_sorted(t_list *stack_a)
{
    t_list  *head;
    t_list  *prev_node;
    t_list  *next_node;

    if(stack_a == NULL)
        return(false);
    head = stack_a;
    prev_node = head;
    next_node = prev_node->next;
    while (next_node != head)
    {
        if (prev_node->value > next_node->value)
            return(false);
        prev_node = next_node;
        next_node = next_node->next;
    }
    return(true);
}
void simple_sorting(t_list **stack_a, t_list **stack_b)
{
int min_position;

min_position = 0;
if (stack_a == NULL || *stack_a == NULL)
    return ;
if (is_sorted(*stack_a) == true)
    return ;
while (*stack_a != NULL)
{
    min_position = find_min_position(*stack_a);
    rotation(stack_a, min_position);
    pb(stack_a, stack_b); 
}
while (*stack_b != NULL)
    pa(stack_a, stack_b);

}
