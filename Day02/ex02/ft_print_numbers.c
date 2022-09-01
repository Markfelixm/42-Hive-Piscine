/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:22:23 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/11 16:27:09 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);

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
