#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

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
		printf("%d\n", ft_ultimate_range(&range, a, b));
		//ft_ultimate_range(&range, a, b);
		while (i < (b - a))
		{
			printf("%d\n", range[i]);
			i++;
		}
	}
	return (0);
}
