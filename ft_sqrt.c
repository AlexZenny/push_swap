/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azieniuk <azieniuk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 21:36:40 by azieniuk          #+#    #+#             */
/*   Updated: 2026/08/21 21:36:40 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

// #include <stdio.h>
// #include <stdlib.h>
//
// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	printf("Square root of %d is %d\n", atoi(argv[1]), ft_sqrt(atoi(argv[1])));
// }
