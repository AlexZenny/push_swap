/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:45:27 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/24 19:53:41 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_stack(t_list **stack)
{
    t_list *temp;

    temp = (*stack);
    if (!(*stack))
    {
        ft_printf("NULL\n");
        return ;
    }
    ft_printf("[ ");
	ft_printf("%d ", temp->value);
	temp = temp->next;
	while (temp != (*stack))
    {
        ft_printf("%d ", temp->value);
		temp = temp->next;
    }
	ft_printf("]\n");
}

void	ft_print_stacks(t_list **stack_a, t_list **stack_b)
{
    ft_printf("stack_a: ");
    ft_print_stack(stack_a);
    ft_printf("stack_b: ");
    ft_print_stack(stack_b);
}

// int	main(void)
// {
// 	t_list *lst_a1 = malloc(sizeof(t_list));
// 	t_list *lst_a2 = malloc(sizeof(t_list));
// 	t_list *lst_a3 = malloc(sizeof(t_list));
// 	t_list *lst_a4 = malloc(sizeof(t_list));
// 	t_list *lst_a5 = malloc(sizeof(t_list));
// 	t_list *lst_b1 = NULL;
// 	lst_a1->next = lst_a2;
// 	lst_a1->prev = lst_a5;
// 	lst_a2->next = lst_a3;
// 	lst_a2->prev = lst_a1;
// 	lst_a3->next = lst_a4;
// 	lst_a3->prev = lst_a2;
// 	lst_a4->next = lst_a5;
// 	lst_a4->prev = lst_a3;
// 	lst_a5->next = lst_a1;
// 	lst_a5->prev = lst_a4;
// 	lst_a1->value = 1;
// 	lst_a2->value = 2;
// 	lst_a3->value = 3;
// 	lst_a4->value = 4;
// 	lst_a5->value = 5;
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	pb(&lst_a1, &lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	pb(&lst_a1, &lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	pb(&lst_a1, &lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	pb(&lst_a1, &lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	pb(&lst_a1, &lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	pb(&lst_a1, &lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	sb(&lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	rotate(&lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	sb(&lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	rotate(&lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	sb(&lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	rotate(&lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	sb(&lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	rotate(&lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	sb(&lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// 	rotate(&lst_b1);
// 	ft_print_stacks(&lst_a1, &lst_b1);
// }
