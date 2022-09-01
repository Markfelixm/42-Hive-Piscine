#include <stdio.h>

void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int	hold;

	hold = *a;
	*a = *b;
	*b = hold;
}

int	main(void)
{
	int	c;
	int	d;

	c = 5;
	d = 7;
	ft_swap(&c, &d);
	printf("5 is now %d\n", c);
	printf("7 is now %d\n", d);
	return (0);
}
