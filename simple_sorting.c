/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 14:43:26 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/25 14:48:18 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rotation(t_list **stack_a, int min_position, int len)
{
    int counter;

    counter = 0;
    if (stack_a == NULL || *stack_a == NULL)
        return(-1);
    while (i != min_position)
    {
        if (min_position <= len / 2)
            ft_rotate(stack_a);
        else 
            ft_rev_rotate(stack_a);
        counter++;
    }
    return(counter);
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
        len++;
    return(len);
} 

void simple_sorting(t_list **stack_a, t_list *options, )
{
t_list *first;
t_list *cursor;


first = *stack_a;
cursor = *stack_a;
cursor = cursor->next;

if (options.mode = SIMPLE)
{

}
}
