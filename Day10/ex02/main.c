#include <stdio.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int));

int	makezero(int n)
{
	return (n * 2);
}

int	main(void)
{
	int	table[5] = {5, 6, 2, 8, 9};
	int	length = 5;
	int	*results;
	int	i;

	i = 0;
	results = (int *)malloc(sizeof(*results) * length);
	results = ft_map(table, length, &makezero);
	while (i < length)
	{
		printf("%d\n", results[i]);
		i++;
	}
	return (0);
}
