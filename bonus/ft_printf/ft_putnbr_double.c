/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 18:02:32 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/01 18:02:36 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_double(int fd, double n)
{
	int		res;
	int		count;
	double	decimal_point;
	int		before_point;

	count = 0;
	before_point = n;
	decimal_point = n * 100;
	res = decimal_point;
	decimal_point = (double)res / 100;
	decimal_point = decimal_point * 100 - (before_point * 100);
	res = decimal_point;
	count += ft_putnbr(fd, n);
	count += ft_putchar(fd, '.');
	count += ft_putnbr(fd, res);
	return (count);
}
