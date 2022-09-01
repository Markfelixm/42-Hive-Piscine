#include <stdio.h>
#include <unistd.h>

void	string1(char *str)
{
	printf("%s\n", str);
}

void	string2(char str[])
{
	printf("%s\n", str);
}

void	string3(char str[])
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, str + i++, 1);
	write(1, "\n", 1);
}

void	string4(char str[])
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

void	string5(char *str)
{
	write(1, str, 4);
	write(1, "\n", 1);
}

int	main(void)
{
	char	*s;

	s = "fourtytwo";
	string1(s);
	string2(s);
	string3(s);
	string4(s);
	string5(s);

	char	*something;
	char	*holder;

	something = "hello there";
	holder = &something[2];
	printf("%c\n", *(something + 1));
	printf("%c\n", something[1]);
	printf("%s\n", holder);
	return (0);
}
