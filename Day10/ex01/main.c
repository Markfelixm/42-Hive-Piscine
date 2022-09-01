#include <stdio.h>

void	ft_foreach(int *tab, int length, void (*f)(int));

void	ftry(int n)
{
	printf("%i\n", n);
}

int	main(void)
{
	int	table[5] = {3, 6, 9, 12, 15};
	int len = 5;

	ft_foreach(table, len, &ftry);
	return (0);
}
