/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:34:33 by arajaobe          #+#    #+#             */
/*   Updated: 2026/02/19 13:24:14 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(int fd, char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(fd, s++, 1);
		count++;
	}
	return (count);
}
