#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	a[] = "this";
	char	b[] = "thata";

	//a = "this";
	//b = "that";
	ft_strcpy(a, b);
	printf("mine: %s\n", a);
	//printf("mine: %s\n", ft_strcpy(a, b));
	printf("theirs: %s\n", strcpy(a, b));
	return (0);
}
