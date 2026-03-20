/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:16:15 by arajaobe          #+#    #+#             */
/*   Updated: 2026/02/19 13:41:51 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(int fd, char c);
int		ft_putnbr(int fd, int n);
int		ft_putnbr_double(int fd, double n);
int		ft_putstr(int fd,char *s);
int		ft_printf(int fd, const char *format, ...);
int		ft_printhexa(int fd, unsigned int n, char c);
int		ft_printhexalong(int fd, unsigned long n, char c);
int		ft_putunsnbr(int fd, unsigned int n);
int		ft_printpointer(int fd, void *p);

#endif
