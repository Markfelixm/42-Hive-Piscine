#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void);

int	main(void)
{
	//ft_print_alphabet();
	char *a;

	a = "abc";
	write(1, a, 3);
	//printf("%s\n", a);
}
