/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extras.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 01:35:28 by azieniuk          #+#    #+#             */
/*   Updated: 2026/07/21 01:35:28 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *cc)
{
	write(1, &c, sizeof(char));
	(*cc)++;
}

void	ft_putstr(char *s, int *cc)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)", cc);
		return ;
	}
	i = 0;
	while (s[i])
		ft_putchar(s[i++], cc);
}

void	ft_putnbr(long i, int *cc)
{
	if (i < 0)
	{
		i = -i;
		ft_putchar('-', cc);
	}
	if (i >= 0 && i < 10)
		ft_putchar(i + '0', cc);
	else
	{
		ft_putnbr(i / 10, cc);
		ft_putnbr(i % 10, cc);
	}
}

void	ft_putnbr_unsigned(unsigned long long i, int *cc)
{
	if (i < 10)
		ft_putchar(i + '0', cc);
	else
	{
		ft_putnbr_unsigned(i / 10, cc);
		ft_putnbr_unsigned(i % 10, cc);
	}
}

void	ft_puthex(unsigned long long i, int offset, int *cc)
{
	if (i < 10)
		ft_putchar(i + '0', cc);
	else if (i < 16)
		ft_putchar(i + offset, cc);
	else
	{
		ft_puthex(i / 16, offset, cc);
		ft_puthex(i % 16, offset, cc);
	}
}
