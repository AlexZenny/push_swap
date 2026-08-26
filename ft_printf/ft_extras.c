/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extras.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 01:35:28 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/26 20:07:03 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *cc, int fd)
{
	write(fd, &c, sizeof(char));
	(*cc)++;
}

void	ft_putstr(char *s, int *cc, int fd)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)", cc, fd);
		return ;
	}
	i = 0;
	while (s[i])
		ft_putchar(s[i++], cc, fd);
}

void	ft_putnbr(long i, int *cc, int fd)
{
	if (i < 0)
	{
		i = -i;
		ft_putchar('-', cc, fd);
	}
	if (i >= 0 && i < 10)
		ft_putchar(i + '0', cc, fd);
	else
	{
		ft_putnbr(i / 10, cc, fd);
		ft_putnbr(i % 10, cc, fd);
	}
}

void	ft_putnbr_unsigned(unsigned long long i, int *cc, int fd)
{
	if (i < 10)
		ft_putchar(i + '0', cc, fd);
	else
	{
		ft_putnbr_unsigned(i / 10, cc, fd);
		ft_putnbr_unsigned(i % 10, cc, fd);
	}
}

void	ft_puthex(unsigned long long i, int offset, int *cc, int fd)
{
	if (i < 10)
		ft_putchar(i + '0', cc, fd);
	else if (i < 16)
		ft_putchar(i + offset, cc, fd);
	else
	{
		ft_puthex(i / 16, offset, cc, fd);
		ft_puthex(i % 16, offset, cc, fd);
	}
}
