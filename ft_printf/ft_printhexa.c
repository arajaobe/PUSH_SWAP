/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:39:57 by arajaobe          #+#    #+#             */
/*   Updated: 2026/02/19 13:27:36 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printhexabig(int fd, unsigned int n1, unsigned int n2, char c);
static int	printhexasmall(int fd, unsigned int n, char c);

int	ft_printhexa(int fd, unsigned int n, char c)
{
	int	count;

	count = 0;
	if (n > 15)
		count = printhexabig(fd, n, n, c);
	else
		count = printhexasmall(fd, n, c);
	return (count);
}

static int	printhexabig(int fd, unsigned int n1, unsigned int n2, char c)
{
	unsigned int	numb;
	int				count;

	count = 0;
	numb = n1;
	if (numb > 15 || numb != 0)
	{
		numb = numb / 16;
		count += printhexabig(fd, numb, n1 % 16, c);
	}
	if (n2 <= 9)
		count += ft_putchar(fd, n2 + '0');
	else if (n2 >= 10 && n2 <= 15)
		count += ft_putchar(fd, n2 - 10 + c);
	return (count);
}

static int	printhexasmall(int fd, unsigned int n, char c)
{
	int	count;

	count = 0;
	if (n <= 9)
		count += ft_putchar(fd, n + '0');
	else if (n >= 10 && n <= 15)
		count += ft_putchar(fd, n - 10 + c);
	return (count);
}
