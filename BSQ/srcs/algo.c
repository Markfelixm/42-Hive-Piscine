/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:09:26 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/31 18:16:00 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

unsigned short	grow_sq(t_map_data *data, int y, int x)
{
	int	diag;
	int	right;
	int	down;

	if (data->map[y][x] == 0)
		return (0);
	else
	{
		diag = 0;
		right = 0;
		down = 0;
		if (y + 1 < data->height && x + 1 < data->width)
			diag = data->map[y + 1][x + 1];
		if (y < data->height && x + 1 < data->width)
			right = data->map[y][x + 1];
		if (y + 1 < data->height && x < data->width)
			down = data->map[y + 1][x];
		return (1 + min_of_3(diag, right, down));
	}
}

void	grow_squares(t_map_data *data)
{
	int	y;
	int	x;

	data->biggest_sq = 0;
	y = data->height - 1;
	while (y >= 0)
	{
		x = data->width - 1;
		while (x >= 0)
		{
			data->map[y][x] = grow_sq(data, y, x);
			if (data->map[y][x] > data->biggest_sq)
				data->biggest_sq = data->map[y][x];
			x--;
		}
		y--;
	}
}

void	locate_biggest_sq(t_map_data *data, int *y, int *x)
{
	bool	should_break;

	should_break = false;
	*y = 0;
	while (*y < data->height && !should_break)
	{
		*x = 0;
		while (*x < data->width && !should_break)
		{
			if (data->map[*y][*x] == data->biggest_sq)
			{
				(*y)--;
				(*x)--;
				should_break = true;
			}
			(*x)++;
		}
		(*y)++;
	}
}

void	paint_sq(t_map_data *data, char *map)
{
	int	sq_start_y;
	int	sq_start_x;
	int	y;
	int	x;

	locate_biggest_sq(data, &sq_start_y, &sq_start_x);
	y = sq_start_y;
	while (y < sq_start_y + data->biggest_sq)
	{
		x = sq_start_x;
		while (x < sq_start_x + data->biggest_sq)
			map[(y * (data->width + 1)) + x++] = data->full_ch;
		y++;
	}
}
