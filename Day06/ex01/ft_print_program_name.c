/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:41:37 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/17 16:14:33 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	ft_putstr(argv[0]);
	ft_putchar('\n');
	if (argc == 0)
		return (0);
	return (0);
}

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}
