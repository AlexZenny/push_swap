/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 17:47:14 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/26 19:52:05 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_pointer(int *cc, va_list args, int fd)
{
	unsigned long long	p;

	p = (unsigned long long)va_arg(args, void *);
	if (!p)
	{
		ft_putstr("(nil)", cc, fd);
		return ;
	}
	ft_putstr("0x", cc, fd);
	ft_puthex(p, HEX_OFFSET_LOW_CASE, cc, fd);
}

static void	ft_parseconv(char cnv, int fd, int *cc, va_list args)
{
	if (cnv == 'c')
		ft_putchar(va_arg(args, int), cc, fd);
	if (cnv == '%')
		ft_putchar('%', cc, fd);
	if (cnv == 'd' || cnv == 'i')
		ft_putnbr(va_arg(args, int), cc, fd);
	if (cnv == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), cc, fd);
	if (cnv == 's')
		ft_putstr(va_arg(args, char *), cc, fd);
	if (cnv == 'x')
		ft_puthex(va_arg(args, unsigned int), HEX_OFFSET_LOW_CASE, cc, fd);
	if (cnv == 'X')
		ft_puthex(va_arg(args, unsigned int), HEX_OFFSET_UP_CASE, cc, fd);
	if (cnv == 'p')
		ft_handle_pointer(cc, args, fd);
}

// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;
// 	int		i;
// 	int		cc;

// 	va_start(args, format);
// 	i = 0;
// 	cc = 0;
// 	while (format[i])
// 	{
// 		if (format[i] == '%' && format[i + 1])
// 		{
// 			ft_parseconv(format[++i], &cc, args);
// 			i++;
// 		}
// 		else
// 			ft_putchar(format[i++], &cc);
// 	}
// 	va_end(args);
// 	return (cc);
// }
int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		cc;

	va_start(args, format);
	i = 0;
	cc = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			ft_parseconv(format[++i], fd, &cc, args);
			i++;
		}
		else
			ft_putchar(format[i++], &cc, fd);
	}
	va_end(args);
	return (cc);
}
// #include <stdio.h>
// #include <limits.h>
//
// int	main(void)
// {
// 	char			c = 'A';
// 	char			*s = NULL;
// 	void			*p = s;
// 	int				d = -1;
// 	int				i = d;
// 	unsigned int	u = -1;
// 	int				x = INT_MIN;
// 	int				X = INT_MAX;
// 	int				c_count_a;
// 	int				c_count_b;
//
// c_count_a = printf("og_printf(): c=%c, s=%s, p=%p, d=%d, i=%i, u=%u, "
// 		"x=%x, X=%X, per=%%\n", c, s, p, d, i, u, x, X);
// c_count_b = ft_printf("ft_printf(): c=%c, s=%s, p=%p, d=%d, i=%i, u=%u, "
// 		"x=%x, X=%X, per=%%\n", c, s, p, d, i, u, x, X);
// printf("c_count_a = %d\n", c_count_a);
// printf("c_count_b = %d\n", c_count_b);
// }
// int	ft_printf(const char *format, ...) __attribute__((format(printf,1,2)))
