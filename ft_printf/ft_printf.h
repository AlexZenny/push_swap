/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 01:35:14 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/29 15:30:49 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define HEX_OFFSET_LOW_CASE 87
# define HEX_OFFSET_UP_CASE 55

int		ft_printf_fd(int fd, const char *format, ...);
void	ft_putchar(char c, int *cc, int fd);
void	ft_putstr(char *s, int *cc, int fd);
void	ft_putnbr(long int i, int *cc, int fd);
void	ft_putnbr_unsigned(unsigned long long i, int *cc, int fd);
void	ft_puthex(unsigned long long i, int offset, int *cc, int fd);

#endif
