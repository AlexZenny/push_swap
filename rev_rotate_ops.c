/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:34:28 by tmalyshi          #+#    #+#             */
/*   Updated: 2026/08/11 20:44:26 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_rotate(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = temp;
}
void	*ft_rotate_both(t_list **lst)
{
	ft_rotate(*stack_a);
	ft_rotate(*stack_b);
}