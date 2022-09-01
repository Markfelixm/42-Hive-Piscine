/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:11:19 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/11 16:26:28 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	first_letter;
	char	last_letter;
	char	letter;

	first_letter = 'a';
	last_letter = 'z';
	letter = first_letter;
	while (letter <= last_letter)
	{
		ft_putchar(letter);
		letter++;
	}
	ft_putchar('\n');
}
