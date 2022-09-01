/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:47:51 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/11 16:27:00 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);

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
