/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 23:42:09 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/31 02:24:17 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort(t_data *data, float dis)
{
	t_mode	*mode;
	int		n;

	mode = &data->options.mode;
	n = count_stack_members(&data->stack_a);
	if (*mode == ADAPTIVE)
	{
		if (dis < 0.2)
			simple_sort(data);
		if (dis > 0.2 && dis < 0.5)
			medium_sort(data, n);
		if (dis > 0.5)
			ft_printf_fd(1, "Place complex sort here\n");
		return ;
	}
	if (*mode == SIMPLE)
		simple_sort(data);
	if (*mode == MEDIUM)
		medium_sort(data, n);
	if (*mode == COMPLEX)
		ft_printf_fd(1, "Place complex sort here\n");
}
