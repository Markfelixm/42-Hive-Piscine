#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_strdup(char *src);

int		ft_strlen(char *str);

int	main(void)
{
	char	a[3];
	char	*b;
	char	*c;
	char	*aa;
	char	*bb;

	a[0] = 'a';
	a[1] = 'b';
	a[2] = 'c';
	//a[3] = '\0';
	aa = ft_strdup("hhhhhhh");
	bb = ft_strdup("hhhhhhh");
	c = strdup(a);
	printf("\n%s\n", aa);
	printf("%s\n", bb);
	printf("a size: %lu\n", sizeof(a));
	printf("b size: %lu\n", sizeof(b));
	printf("c size: %lu\n", sizeof(c));
	printf("%d\n", ft_strlen(a));
	write(1, &a[2], 1);
	return (0);
}
