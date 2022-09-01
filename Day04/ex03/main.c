#include <stdio.h>

int	ft_recursive_power(int nb, int power);

int	main(void)
{
	printf("27\t%d\n", ft_recursive_power(3, 3));
	printf("0\t%d\n", ft_recursive_power(-3, -3));
	printf("-27\t%d\n", ft_recursive_power(-3, 3));
	printf("0\t%d\n", ft_recursive_power(3, -3));
	printf("0\t%d\n", ft_recursive_power(0, 3));
	printf("1\t%d\n", ft_recursive_power(1, 3));
	printf("1\t%d\n", ft_recursive_power(1, 0));
	printf("1\t%d\n", ft_recursive_power(0, 0));
	printf("1\t%d\n", ft_recursive_power(1, 1));
	return (0);
}
