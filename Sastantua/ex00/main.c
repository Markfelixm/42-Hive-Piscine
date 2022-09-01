#include <stdlib.h>

void	ft_putchar(char c);

void	sastantua(int size);

int	main(int argc, char *argv[])
{
	int	size;

	size = atoi(argv[1]);
	if (argc == 2)
		sastantua(size);
	return (0);
}
