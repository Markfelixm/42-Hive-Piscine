#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main(void)
{
	int	c;
	int	d;

	ft_div_mod(15, 7, &c, &d);
	printf("div is %d\n", c);
	printf("mod is %d\n", d);
	return (0);
}
