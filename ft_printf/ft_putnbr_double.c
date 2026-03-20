
#include "ft_printf.h"

int	ft_putnbr_double(int fd, double n)
{
	int res;
	int count;
	double decimal_point;
	int	before_point;

	count  = 0;
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
