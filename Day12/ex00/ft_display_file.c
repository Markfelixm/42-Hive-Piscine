/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:18:30 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/24 12:40:46 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

int	main(int argc, char **argv)
{
	char	buffer[BUFFER_SIZE + 1];
	int		fd;
	int		read_size;

	if (ft_handle_argc(argc))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "File failed to open.\n", 21);
		return (1);
	}
	read_size = read(fd, buffer, BUFFER_SIZE);
	buffer[read_size] = '\0';
	ft_putstr(buffer);
	if (close(fd) == -1)
	{
		write(2, "File failed to close.\n", 22);
		return (1);
	}
	return (0);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	ft_strlen(char *str)
{
	if (*str)
		return (1 + ft_strlen(++str));
	return (0);
}

bool	ft_handle_argc(int argc)
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (true);
	}
	else if (argc != 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (true);
	}
	return (false);
}
