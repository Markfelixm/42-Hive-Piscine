#include <stdio.h>

int	ft_strlen(char *str)
{
	if (*str)
		return (1 + ft_strlen(++str));
	return (0);
}

// int	ft_strlen(char *str)
// {
// 	int	len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }

int main(int argc, char **argv)
{
	printf("%d\n", ft_strlen(argv[1]));
	return (0);
}
