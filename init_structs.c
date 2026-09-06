/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:02:44 by tmalyshi          #+#    #+#             */
/*   Updated: 2026/08/31 16:04:20 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_counters(t_data *data)
{
	data->ops.pa_count = 0;
	data->ops.pb_count = 0;
	data->ops.sa_count = 0;
	data->ops.sb_count = 0;
	data->ops.ss_count = 0;
	data->ops.ra_count = 0;
	data->ops.rb_count = 0;
	data->ops.rr_count = 0;
	data->ops.rra_count = 0;
	data->ops.rrb_count = 0;
	data->ops.rrr_count = 0;
	data->ops.total_count = 0;
}

void	initialize_data(t_data *data)
{
	data->options.mode = ADAPTIVE;
	data->options.mode_status = 0;
	data->options.bench = false;
	data->stack_a = NULL;
	data->stack_b = NULL;
}
