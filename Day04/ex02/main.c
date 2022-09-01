#include <stdio.h>

int	ft_iterative_power(int nb, int power);

int	main(void)
{
	printf("%d\n", ft_iterative_power(-2, -2));
	printf("%d\n", ft_iterative_power(-2, 3));
	printf("%d\n", ft_iterative_power(1, 1));
	printf("%d\n", ft_iterative_power(0, 1));
	printf("%d\n", ft_iterative_power(1, 0));
	printf("%d\n", ft_iterative_power(0, 0));
	printf("%d\n", ft_iterative_power(3, 4));
	printf("%d\n", ft_iterative_power(4, 2));
	return (0);
}
