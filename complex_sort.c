/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:02:38 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/29 15:58:34 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_largest_rank(t_list *stack_a)
{
    t_list  *current;
    t_list  *head;
    t_list  *max_rank_node;
    int     position;
    int     min_rank;

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

void    complex_sort(t_list **stack_a, t_list **stack_b)
{
    assign_ranks(stack_a, stack_len(*stack_a));
    find_largest_rank()


}
