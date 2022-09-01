/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_rush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:28:36 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/28 20:52:53 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>

t_rushes	*gen_rushes(t_input *input)
{
	t_rushes	*rushes;

	rushes = init_rushes(input->read_size);
	rushes->rush00 = gen_rush(input, 0);
	rushes->rush01 = gen_rush(input, 1);
	rushes->rush02 = gen_rush(input, 2);
	rushes->rush03 = gen_rush(input, 3);
	rushes->rush04 = gen_rush(input, 4);
	return (rushes);
}

char	*gen_rush(t_input *input, int variant)
{
	t_pos		*pos;
	char		*rush;
	int			i;

	pos = malloc(sizeof(t_pos));
	pos->x = input->cols;
	pos->y = input->rows;
	pos->w = 1;
	pos->l = 1;
	rush = malloc(sizeof(char) * input->read_size);
	i = 0;
	while (pos->l <= pos->y)
	{
		while (pos->w <= pos->x)
		{
			rush[i++] = parse_variant(pos, variant);
			pos->w++;
		}
		pos->w = 1;
		if (!(pos->x < 1 || pos->y < 1))
			rush[i++] = '\n';
		pos->l++;
	}
	free(pos);
	return (rush);
}

char	parse_variant(t_pos *pos, int variant)
{
	if (variant == 0)
		return (rush00_parse_pos(pos));
	else if (variant == 1)
		return (rush01_parse_pos(pos));
	else if (variant == 2)
		return (rush02_parse_pos(pos));
	else if (variant == 3)
		return (rush03_parse_pos(pos));
	else if (variant == 4)
		return (rush04_parse_pos(pos));
	else
		return ('X');
}

t_rushes	*init_rushes(int read_size)
{
	t_rushes	*rushes;

	rushes = malloc(sizeof(t_rushes));
	rushes->rush00 = malloc(sizeof(char) * read_size);
	rushes->rush01 = malloc(sizeof(char) * read_size);
	rushes->rush02 = malloc(sizeof(char) * read_size);
	rushes->rush03 = malloc(sizeof(char) * read_size);
	rushes->rush04 = malloc(sizeof(char) * read_size);
	return (rushes);
}
