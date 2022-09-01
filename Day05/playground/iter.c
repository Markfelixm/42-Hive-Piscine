#include <stdio.h>

int	main(void)
{
	char	*needle = "needle";
	char	*haystack = "haystack";
	int		i;

	i = 0;
	while (haystack[i] != '\0')
	{
		while (needle[0] != haystack[0])
			haystack++;
		while (needle[i] != '\0')
		{
			if (needle[i] == haystack[i])
				i++;
			else
				break ;
		}
		i++;
	}
	printf("%s", )
	return (0);
}
