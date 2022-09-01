/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:09:06 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/31 18:16:00 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_map_data	*set_invalid(t_map_data *data)
{
	data->is_valid = false;
	data->height = 0;
	return (data);
}

int	handle_nl(char *map, t_map_data *data, int line_nb, int i)
{
	int	j;
	int	col_nb;

	j = i - data->width;
	col_nb = 0;
	data->map[line_nb] = malloc(sizeof(unsigned short) * (data->width + i + 1));
	while (j < i)
	{
		if (map[j] == data->obstacle_ch)
			data->map[line_nb][col_nb++] = 0;
		else if (map[j] == data->empty_ch)
			data->map[line_nb][col_nb++] = 1;
		j++;
	}
	return (data->width + 1);
}

t_map_data	*parse_map(char *map, t_map_data *data, int i)
{
	int	nl_i;
	int	line_nb;

	data->map = malloc(sizeof(unsigned short *) * data->height);
	data->width = get_nl_pos(map, i);
	if (data->width < 1)
		return (set_invalid(data));
	nl_i = data->width + i;
	line_nb = 0;
	while (map[i])
	{
		if (i == nl_i)
		{
			if (map[i] != '\n')
				return (set_invalid(data));
			nl_i += handle_nl(map, data, line_nb++, i);
		}
		else if (map[i] != data->empty_ch && map[i] != data->obstacle_ch)
			return (set_invalid(data));
		i++;
	}
	if (line_nb != data->height || map[i - 1] != '\n')
		return (set_invalid(data));
	return (data);
}

t_map_data	*get_map_data(char *map)
{
	t_map_data	*data;
	int			i;

	data = malloc(sizeof(t_map_data));
	if (!data)
		return (NULL);
	data->is_valid = true;
	i = 0;
	get_metadata(map, data, &i);
	parse_map(map, data, i);
	return (data);
}
