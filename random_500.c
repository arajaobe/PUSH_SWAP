
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void generate_array(int *arr, int n) {
    for (int i = 0; i < n; i++) arr[i] = i + 1;
}

void block_shuffle(int *arr, int n, int block_size) {
    srand(time(NULL));
    for (int i = 0; i < n; i += block_size) {
        if (rand() % 2) { // 50% chance to reverse block
            int left = i;
            int right = (i + block_size - 1 < n) ? i + block_size - 1 : n - 1;
            while (left < right) {
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        }
    }
}


/*int main() {
    int n = 500;
    int arr[500];
    generate_array(arr, n);
    block_shuffle(arr, n, 1); // reverse random blocks of 10

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}*/


/*int main() {
    int n = 500;
    for (int i = n; i >= 1; i--) {
        printf("%d ", i);
    }
    return 0;
}*/

/*int main ()
{
	char *big = " Hell oworld";
	char *small  = "w";
	char *res;
	res = malloc(10);

	res = ft_strnstr(big, small, strlen(big));
	printf("%d", ft_atoi(" -+69 8"));

}*/

int main ()
{
	char *a = "pim pew bimm\0hillo";
	//int c = countword(a, ',');
	char **p = ft_split(a, 'i');
	for(int i = 0; i < countword(a, 'i') + 1; i++)
		printf("%d : %s\n",i, p[i]);
	return 0;
}
