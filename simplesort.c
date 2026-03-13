
#include <stdio.h>



void	insertsort(int	*tab, int size)
{
	int i;
	int j;
	int key;

	i = 1;
	while (i < size)
	{
		key = tab[i];
		j = i - 1;
		while (j >=0 && tab[j] > key)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = key;
		i++;
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10;
		res = res + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}


int main(int argc, char **argv)
{
	int tab[argc - 1];

	for(int j = 0; j < argc - 1; j++)
		tab[j] = ft_atoi(argv[j + 1]);

	//insertsort(tab, argc - 1);
	for(int i = 0; i < argc - 1; i++)
		printf("%d ", tab[i]);
	return 0;
}


