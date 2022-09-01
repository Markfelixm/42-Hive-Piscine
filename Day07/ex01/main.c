#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

int	main(int argc, char **argv)
{
	int	*range;
	int	i;
	int	a;
	int	b;


	i = 0;
	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		range = ft_range(a, b);
		while (i < (b - a))
		{
			printf("%d\n", range[i]);
			i++;
		}
	}
	return (0);
}
