
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


typedef struct numbers
{
	int	content;
	struct numbers *next;
}number_list;

/*typedef	struct action
{

	number_list	*stack;
	struct action	*next;
}t_action;*/


number_list	*ft_lstnew(int content)
{
	number_list	*head;

	head = malloc(sizeof(number_list));
	if (!head)
		return (NULL);
	head -> content = content;
	head -> next = NULL;
	return (head);
}

void print_num(number_list *head)
{
	number_list *p;
	p = head;

	while (p != NULL)
	{
		printf("%d \n", p -> content);

		p = p -> next;
	}
}

int	count_nodes(number_list *head)
{
	int	count;
	number_list *ptr;

	count = 0;
	if (head == NULL)
		return 0;
	ptr = head;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	free(ptr);
	ptr = NULL;
	return count;
}

int	find_content(number_list *head, int pos)
{
	int i;
	int	res;
	number_list *p;

	p = head;
	i = 1;
	if (pos == 0)
		return 0;
	while (i <= pos)
	{
		res = p->content;
		p = p->next;
		i++;
	}
	return res;
}

static number_list	*find_link(number_list *head, int pos)
{
	int i;

	number_list *p;
	number_list *res;

	p = head;
	i = 1;
	if (pos == 0)
		return 0;
	while (i <= pos)
	{
		res = p;
		p = p->next;
		i++;
	}
	return res;
}


void	ft_lstadd_front(number_list **lst, number_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	insertsort(number_list	*head, int size)
{
	int i;
	int j;
	int key;
	number_list	*tab;
	number_list *tab2;

	tab = head;
	tab2 = head;
	i = 2;
	while (i <= size)
	{
		key = find_content(head, i);
		j = i - 1;
		while (j >=1 && find_content(head, j) > key)
		{
			tab = find_link(head, j + 1);
			tab2 = find_link(head, j);
			tab->content = tab2->content;
			j--;
		}
		tab = find_link(head, j+1);
		tab->content = key;
		i++;
	}
}



void	sa(number_list *head)
{
	number_list	*p;
	int	temp;

	p = head;
	temp = p->content;
	p->content = p->next->content;
	p->next->content = temp;
}



number_list	*list_fillers(int stop, ...)
{
	va_list args;
	va_start(args, stop);
	number_list *one;
	number_list *two;
	number_list *three;
	int i;

	one = ft_lstnew( va_arg(args, int));
	if (stop == 1)
		return one;
	two = ft_lstnew(va_arg(args, int));
	one->next = two;
	if (stop == 2)
		return one;
	i = 2;
	three = one->next;
	while (i < stop)
	{
		two = ft_lstnew(va_arg(args, int));;
		three->next = two;
		three = three->next;
		i++;
	}
	return one;
}



int main()
{
	number_list *one;
	number_list	*two;
	number_list *test;

	/*one = ft_lstnew(4);
	two = ft_lstnew(3);
	one->next = two;
	two = ft_lstnew(1);
	one->next->next = two;
	two = ft_lstnew(2);
	one->next->next->next = two;*/

	//one = list_fillers(100, 73, 418, 205, 11, 392, 147, 256, 89, 304, 167, 450, 29, 311, 98, 274, 6, 359, 120, 487, 53, 222, 401, 76, 190, 333, 15, 268, 144, 379, 92, 410, 37, 251, 468, 109, 342, 58, 297, 184, 425, 12, 361, 207, 95, 470, 134, 286, 64, 318, 171, 443, 23, 352, 214, 81, 399, 160, 275, 48, 326, 118, 462, 7, 289, 374, 154, 230, 96, 421, 176, 339, 57, 263, 148, 455, 31, 308, 122, 344, 69, 498, 213, 87, 365, 140, 271, 419, 101, 236, 52, 384, 165, 295, 432, 19, 357, 246, 473, 128, 309);
	one = list_fillers(4, 4, 3, 1, 2);
	//two = list_fillers(4, 0, 0, 0, 0);

	test = find_link(one, 1);
	/*print_num(one);
	printf("number of nodes: %d\n", count_nodes(one));
	printf("content of 3rd node: %d\n", find_content(one, 1));
	printf("content of 3rd node: %d\n", test->content);*/

	//insertsort(one, count_nodes(one));
	//sa(one);

	//pb(one,&two);

	print_num(one);
	printf("\n");
	print_num(two);


	/*printf("%d\n", one->content);
	printf("%d\n", one->next->content);
	printf("%d\n", one->next->next->content);
	printf("%d\n", one->next->next->next->content);*/
	return 0;

}

