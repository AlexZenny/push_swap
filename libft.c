/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 23:36:50 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/20 23:42:06 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long	i;
	long	sign;
	long	res;

	i = 0;
	res = 0;
    sign = 1;
    while (((nptr[i] >= 9) && (nptr[i] <= 13)) || (nptr[i] == 32)) 
        i++;
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
            sign = -1;   	  
        if (nptr[i] == '+')
            sign = 1;
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        res = res * 10 + (nptr[i] - '0');
        i++;
    }
    return (res * sign);
}
int ft_strncmp(const char *s1, const char *s2, size_t size)
{
    size_t i;
    
    i = 0;
    while (i < size && s1[i] == s2[i] && s1[i] != '\0')
        i++;
    if (i == size)
        return (0);
    return((unsigned char)s1[i] - (unsigned char)s2[i]);
}