#include <stdio.h>

void	ft_ultimate_ft(int *********nbr);

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

int	main(void)
{
	int a;
	int *a1;
	int **a2;
	int	***a3;
	int	****a4;
	int	*****a5;
	int ******a6;
	int *******a7;
	int ********a8;
	int	*********a9;

	a = 3;
	a1 = &a;
	a2 = &a1;
	a3 = &a2;
	a4 = &a3;
	a5 = &a4;
	a6 = &a5;
	a7 = &a6;
	a8 = &a7;
	a9 = &a8;



	ft_ultimate_ft(a9);
	printf("%d\n", a);
	return (0);
}
