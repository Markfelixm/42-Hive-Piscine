/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:42:12 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/11 18:02:50 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_print_digits(int first, int second, int third);
void	ft_print_delimeter(int first, int second, int third);
void	ft_print_comb(void);

void	ft_print_digits(int first, int second, int third)
{
	ft_putchar(first + '0');
	ft_putchar(second + '0');
	ft_putchar(third + '0');
}

void	ft_print_delimeter(int first, int second, int third)
{
	if (!(first == 7 && second == 8 && third == 9))
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
	int	third;

	first = 0;
	while (first <= 7)
	{
		second = first + 1;
		while (second <= 8)
		{
			third = second + 1;
			while (third <= 9)
			{
				ft_print_digits(first, second, third);
				ft_print_delimeter(first, second, third);
				third++;
			}
			second++;
		}
		first++;
	}
	ft_putchar('\n');
}
