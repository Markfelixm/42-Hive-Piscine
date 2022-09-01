#include <stdio.h>

int	ft_any(char **tab, int (*f)(char*));

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
	if (argc == 10)
		return 0;
	printf("any: %d", ft_any(argv, &yeah));
	return (0);
}
