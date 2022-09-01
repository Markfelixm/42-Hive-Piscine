/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:42:04 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/31 18:16:00 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	parse_maps(char **maps, int nb_of_maps)
{
	int			i;
	t_map_data	*data;

	i = 1;
	while (i < nb_of_maps)
	{
		if (i > 1)
			putstr("\n");
		data = get_map_data(maps[i]);
		if (data->is_valid)
		{
			grow_squares(data);
			maps[i] += data->map_start_i;
			paint_sq(data, maps[i]);
			putstr(maps[i]);
			maps[i] -= data->map_start_i;
		}
		else
			write(2, "map error\n", 10);
		free_data(data, maps[i++]);
	}
	free(maps[0]);
}

void	free_data(t_map_data *data, char *map)
{
	int	i;

	i = data->height;
	while (--i >= 0)
		free(data->map[i]);
	free(data->map);
	free(map);
	free(data);
}

int	main(int argc, char **argv)
{
	get_input(&argc, argv);
	argv[0] = NULL;
	parse_maps(argv, argc);
}
