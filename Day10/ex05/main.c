#include <stdio.h>
#include <stdlib.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int));

int diff(int a, int b)
{
	return a - b;
}

int sdiff(int a, int b)
{
	return b - a;
}

int	main(void)
{
	int len = 8;
	int	t[8] = {2, 1, 0, 0, 0, 0, -1, -10};

	printf("%i\n", ft_is_sort(t, len, &diff));
	printf("%i\n", ft_is_sort(t, len, &sdiff));
	return (0);
}
