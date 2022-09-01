#include <stdio.h>

int	ft_count_if(char **tab, int (*f)(char*));

int	yeah(char *str)
{
	while (*str)
	{
		if (*str == 'a')
			return (1);
		str++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	printf("any: %d", ft_count_if(argv, &yeah));
	return (0);
}
