/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_print_reverse_alphabet.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:45:12 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/11 11:46:08 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_reverse_alphabet(void)
{
	char	first_letter;
	char	last_letter;
	char	letter;

	first_letter = 'z';
	last_letter = 'a';
	letter = first_letter;
	while (letter >= last_letter)
	{
		ft_putchar(letter);
		letter--;
	}
	ft_putchar('\n');
}

int	main(void) {
	ft_print_reverse_alphabet();
}
