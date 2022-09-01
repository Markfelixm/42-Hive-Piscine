#include <stdio.h>

void	ft_ft(int *nbr);

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int	main(void)
{
	int	a;

	ft_ft(&a);
	printf("%d\n", a);
	return (0);
}
