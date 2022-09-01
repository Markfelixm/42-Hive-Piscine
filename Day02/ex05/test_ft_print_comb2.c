#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_comb(void);
void	ft_print_digits(int first, int second);
void	ft_print_delimeter(int first, int second);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_digits(int first, int second)
{
	int	one;
	int	two;
	int	three;
	int	four;

	one = first / 10 % 10;
	two = first % 10;
	three = second / 10 % 10;
	four = second % 10;
	ft_putchar(one + '0');
	ft_putchar(two + '0');
	ft_putchar(' ');
	ft_putchar(three + '0');
	ft_putchar(four + '0');
}

void	ft_print_delimeter(int first, int second)
{
	if (!(first == 98 && second == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	else
	{
		ft_putchar('\n');
	}
}

void	ft_print_comb(void)
{
	int	first;
	int	second;

	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			ft_print_digits(first, second);
			ft_print_delimeter(first, second);
			second++;
		}
		first++;
	}
}

int	main(void)
{
	ft_print_comb();
}
