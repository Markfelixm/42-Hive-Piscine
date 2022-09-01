/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:08:17 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/31 18:16:00 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	*get_content(int fd)
{
	t_list	*list;
	char	buff[READ_BUFF];
	char	*out;
	int		read_size;

	list = NULL;
	while (1)
	{
		read_size = read(fd, buff, READ_BUFF - 1);
		if (read_size == 0)
			break ;
		buff[read_size] = '\0';
		append_node(&list, buff);
	}
	out = malloc(sizeof(char) * (get_list_len(list) * READ_BUFF));
	cat_list(out, list);
	free_list(list);
	return (out);
}

void	get_input(int *argc, char **argv)
{
	int	i;
	int	fd;

	if (*argc == 1)
	{
		(*argc)++;
		argv[1] = get_content(0);
	}
	else
	{
		i = 1;
		while (i < *argc)
		{
			fd = open(argv[i], O_RDONLY);
			argv[i++] = get_content(fd);
			close(fd);
		}
	}
}
