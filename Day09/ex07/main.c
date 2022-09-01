#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_collatz_conjecture(unsigned int base);

int main(int argc, char **argv)
{
	if (argc == 2)
		printf("%u\n", ft_collatz_conjecture(atoi(argv[1])));
	return (0);
}
