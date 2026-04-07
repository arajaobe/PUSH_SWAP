/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:07:13 by arajaobe          #+#    #+#             */
/*   Updated: 2026/02/19 13:25:36 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handlers(int fd, char specifier, va_list args);

int	ft_printf(int fd, const char *format, ...)
{
	va_list		args;
	int			count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			count += handlers(fd, *format, args);
		}
		else
			count += ft_putchar(fd, *format);
		format++;
	}
	va_end(args);
	return (count);
}

static int	handlers(int fd, char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(fd, va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(fd, va_arg (args, char *)));
	else if (specifier == 'p')
		return (ft_printpointer(fd, va_arg (args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(fd, va_arg(args, int)));
	else if (specifier == 'f')
		return (ft_putnbr_double(fd, va_arg (args, double)));
	else if (specifier == 'u')
		return (ft_putunsnbr(fd, va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_printhexa(fd, va_arg(args, unsigned int), 'a'));
	else if (specifier == 'X')
		return (ft_printhexa(fd, va_arg(args, unsigned int), 'A'));
	else if (specifier == '%')
		return (ft_putchar(fd, '%'));
	else
	{
		ft_putchar(fd, '%');
		return (ft_putchar(fd, specifier) + 1);
	}
}
