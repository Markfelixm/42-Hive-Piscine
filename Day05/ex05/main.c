#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char 	a[] = "ee";
	char 	b[] = "onetwothree";

	printf("_____test 1\n");
	printf("mine: %s\n", ft_strstr(a, b));
	printf("theirs: %s\n", strstr(a, b));
	printf("_____test 2\n");
	printf("mine: %s\n", ft_strstr(b, a));
	printf("theirs: %s\n", strstr(b, a));

	return (0);
}
