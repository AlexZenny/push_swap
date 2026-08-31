/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 23:42:09 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/31 16:58:14 by tmalyshi         ###   ########.fr       */
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
		if (dis > 0.2 && dis <= 0.5)
			medium_sort(data, n);
		if (dis > 0.5)
			complex_sort(data);
		return ;
	}
	if (*mode == SIMPLE)
		simple_sort(data);
	if (*mode == MEDIUM)
		medium_sort(data, n);
	if (*mode == COMPLEX)
		complex_sort(data);
}
