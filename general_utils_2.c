/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:47:56 by azieniuk          #+#    #+#             */
/*   Updated: 2026/09/07 16:31:31 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	is_whitespace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (0);
	return (1);
}

int	is_minus(char c)
{
	if (c == '-' || c == '+')
		return (0);
	return (1);
}
