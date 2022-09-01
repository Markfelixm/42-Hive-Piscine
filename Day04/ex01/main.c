#include <stdio.h>

int	ft_recursive_factorial(int nb);

int	main(void)
{
	printf("0! is %d\n", ft_recursive_factorial(0));
	printf("1! is %d\n", ft_recursive_factorial(1));
	printf("8! is %d\n", ft_recursive_factorial(8));
	printf("12! is %d\n", ft_recursive_factorial(12));
	printf("13! is %d\n", ft_recursive_factorial(13));
	printf("14! is %d\n", ft_recursive_factorial(14));
	printf("-11! is %d\n", ft_recursive_factorial(-11));
	return (0);
}
