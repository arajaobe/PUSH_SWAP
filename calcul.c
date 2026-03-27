
#include <stdio.h>
#include <limits.h>

/*int	ft_putnbr_point(int fd, double n)
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
	printf(" before dec pt: %d , after dec pt: %d\n", before_point, res);
	return 0;

}


int main()
{
	int a ,b ,c;
	double result;
	a = 13;
	b = 3;
	result = (double)a / b;
	c = result;

	ft_putnbr_point(1, 15964.6);


	//printf("%lf\n", result);
	//printf("%d\n", c);
	return (0);

}*/


/*int	duplicate(int *array, int size)
{
	int i;
	int j;
	int check;
	int pos;

	check = 0;
	i = 0;
	while (i < size)
	{
		pos = array[i];
		j = i + 1;
		while (j < size)
		{
			if (pos == array[j])
			{
				check = 1;
				return (check);
			}
			j++;
		}
		i++;
	}
	return (check);
}*/



//int main()
//{
//	int tab[] = {2, 3, 6, 1, 6};
//	int res;


//	//res = duplicate(tab, 5);
//	//if (res)
//	//	printf("there is a duplicate");
//	//else
//	//	printf("there is no duplicate");
//	printf("min: %d\n" ,  INT_MIN);
//	printf("max: %d\n" ,  INT_MAX);
//	return 0;

//}
