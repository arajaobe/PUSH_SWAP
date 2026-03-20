/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:18:32 by arajaobe          #+#    #+#             */
/*   Updated: 2026/02/19 13:23:29 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(int fd, void *p)
{
	int	count;

	count = 0;
	if (!p)
	{
		count += ft_putstr(fd, "(nil)");
		return (count);
	}
	count += ft_putstr(fd, "0x");
	count += ft_printhexalong(fd, (unsigned long)p, 'a');
	return (count);
}
