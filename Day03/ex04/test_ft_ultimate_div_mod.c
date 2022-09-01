#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b);

void ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

int	main(void)
{
	int	c;
	int	d;

	c = 22;
	d = 3;
	ft_ultimate_div_mod(&c, &d);
	printf("div is %d\n", c);
	printf("mod is %d\n", d);
	return (0);
}
