/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:46:05 by tmalyshi          #+#    #+#             */
/*   Updated: 2026/08/11 22:47:45 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_rotate(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = *lst;
	*lst = (*lst)->prev;
	(*lst)->next = temp;
}
// void	*ft_rotate_both(t_list **lst)
// {
// 	ft_rotate(*stack_a);
// 	ft_rotate(*stack_b);
// }
int	main(void)
{
	int		a;
	int		b;
	int		c;
	t_list	*stack_a;

	a = 10;
	b = 20;
	c = 30;
	stack_a = ft_lstnew(&a);
	ft_rotate(stack_a);
}
