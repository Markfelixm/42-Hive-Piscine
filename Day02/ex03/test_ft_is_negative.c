#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_is_negative(int n);

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		ft_putchar('N');
	}
	else
	{
		ft_putchar('P');
	}
	ft_putchar('\n');
}

int	main(void)
{
	ft_is_negative(10000000);
	ft_is_negative(1);
	ft_is_negative(-5000);
	ft_is_negative(0);
}
