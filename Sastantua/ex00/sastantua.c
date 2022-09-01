/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:54:13 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/14 20:12:34 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	get_depth(int size);

int	get_width(int size);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	sastantua(int size)
{
	printf("depth: %d\n", get_depth(size));
	printf("width: %d\n", get_width(get_depth(size)));
	// if (size < 1)
	// 	return (0);
	// else
	// {

	// 	if !(size == 1)
	// 		size--;
	// 	else
	// 		exit
	// }
}

int	get_depth(int size)
{
	int	depth;
	int	i;

	depth = 0;
	i = 0;
	while (i < size)
	{
		depth = depth + 3 + i;
		i++;
	}
	return (depth);
}

int	get_width(int size)
{
	int	width;
	int	depth;
	int	i;

	depth = get_depth(size);
	width = depth * 2 + 1;
	i = 0;
	while (i < depth)
	{
		width = width + size;
		i++;
	}
	return (width);
}
