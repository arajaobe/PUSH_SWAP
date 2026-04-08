/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:38:26 by arajaobe          #+#    #+#             */
/*   Updated: 2026/02/19 13:23:45 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsnbr(int fd, unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsnbr(fd, n / 10);
	count += ft_putchar(fd, n % 10 + '0');
	return (count);
}
