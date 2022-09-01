#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	char	number;
	char	last_number;

	number = '0';
	last_number = '9';
	while (number <= last_number)
	{
		ft_putchar(number);
		number++;
	}
	ft_putchar('\n');
}

int	main(void)
{
	ft_print_numbers();
}
