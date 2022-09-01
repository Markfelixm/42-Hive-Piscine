#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str);

int	main(void)
{
	printf("%d\n", (ft_atoi("42") - atoi("42")));
	printf("%d\n", (ft_atoi("-42") - atoi("-42")));
	printf("%d\n", (ft_atoi("--42") - atoi("--42")));
	printf("%d\n", (ft_atoi("  -42") - atoi("  -42")));
	printf("%d\n", (ft_atoi(" +42") - atoi(" +42")));
	printf("%d\n", (ft_atoi(" ++42") - atoi(" ++42")));
	printf("%d\n", (ft_atoi("4f2") - atoi("4f2")));
	printf("%d\n", (ft_atoi("4-2") - atoi("4-2")));
	printf("%d\n", (ft_atoi("424242") - atoi("424242")));
	printf("%d\n", (ft_atoi("      ") - atoi("      ")));
	printf("%d\n", (ft_atoi("-2147483648") - atoi("-2147483648 ")));
	printf("%d\n", (ft_atoi("2147483647") - atoi("2147483647")));
	return (0);
}
