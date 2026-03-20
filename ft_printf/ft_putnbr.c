/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:50:37 by arajaobe          #+#    #+#             */
/*   Updated: 2026/02/19 13:23:41 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int fd, int n)
{
	long int	nbr;
	int			count;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		count += ft_putchar(fd, '-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnbr(fd, nbr / 10);
	count += ft_putchar(fd, nbr % 10 + '0');
	return (count);
}
