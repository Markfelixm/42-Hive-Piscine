/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:08:42 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/31 18:16:00 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_map_data	*get_height(char *map, t_map_data *data, int *i)
{
	while (map[*i] == ' ' || map[*i] == '\t' || map[*i] == '\n'
		|| map[*i] == '\v' || map[*i] == '\f' || map[*i] == '\r')
		(*i)++;
	if (map[*i] == '+')
		(*i)++;
	while (map[*i] == '0')
		(*i)++;
	if (!('0' <= map[*i] && map[*i] <= '9'))
		return (set_invalid(data));
	data->height = str_to_nb(map);
	if (data->height < 1)
		return (set_invalid(data));
	*i += count_digits(data->height);
	return (data);
}

t_map_data	*get_metadata(char *map, t_map_data *data, int *i)
{
	if (!get_height(map, data, i)->is_valid)
		return (set_invalid(data));
	if (map[*i] != '\n' && map[*i] != '\0')
		data->empty_ch = map[(*i)++];
	else
		return (set_invalid(data));
	if (map[*i] != '\n' && map[*i] != '\0')
		data->obstacle_ch = map[(*i)++];
	else
		return (set_invalid(data));
	if (map[*i] != '\n' && map[*i] != '\0')
		data->full_ch = map[(*i)++];
	else
		return (set_invalid(data));
	if (map[(*i)++] != '\n')
		return (set_invalid(data));
	data->map_start_i = *i;
	return (data);
}

int	get_nl_pos(char *map, int i)
{
	int	j;

	j = i;
	while (map[i])
	{
		if (map[i] == '\n')
			return (i - j);
		i++;
	}
	return (-1);
}
