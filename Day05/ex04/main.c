#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char a[] = "abc";
	char b[] = "123456789";

	//ft_strncpy(a, b, 3);
	//strncpy(a, b, 3);
	//ft_strncpy(a, b, 6);
	strncpy(a, b, 6);
	return (0);
}
