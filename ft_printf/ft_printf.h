/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 01:35:14 by azieniuk          #+#    #+#             */
/*   Updated: 2026/07/21 01:35:14 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define HEX_OFFSET_LOW_CASE 87
# define HEX_OFFSET_UP_CASE 55

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *cc);
void	ft_putstr(char *s, int *cc);
void	ft_putnbr(long int i, int *cc);
void	ft_putnbr_unsigned(unsigned long long i, int *cc);
void	ft_puthex(unsigned long long i, int offset, int *cc);

#endif
