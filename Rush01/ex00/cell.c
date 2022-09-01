/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:51:32 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/21 23:24:08 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cell.h"
#include <stdlib.h>

// Returns a pointer to a new cell, or NULL on error.
t_cell	*new_cell(t_context *ctx, int index)
{
	t_cell	*cell;
	int		row;
	int		col;
	int		sqr;

	cell = malloc(sizeof(t_cell));
	if (cell == NULL)
		return (NULL);
	row = index / 9;
	col = index % 9;
	sqr = 3 * (row / 3) + (col / 3);
	cell->row_context = &ctx->rows[row];
	cell->col_context = &ctx->cols[col];
	cell->sqr_context = &ctx->sqrs[sqr];
	cell->guess = 0;
	return (cell);
}

// Returns an array of new cells with the given length.
t_cell	**new_cells(t_context *context, char *input, int length)
{
	t_cell	**cells;
	int		i;
	int		k;

	i = 0;
	k = 0;
	cells = malloc(sizeof(t_cell) * length);
	if (cells == NULL)
		return (NULL);
	while (input[i])
	{
		if (input[i] == '.')
		{
			cells[k] = new_cell(context, i);
			if (cells[k++] == NULL)
				return (NULL);
		}
		i++;
	}
	return (cells);
}

void	free_cells(t_cell **cells, int length)
{
	int	i;

	i = 0;
	while (i < length)
		free(cells[i++]);
}

// Tries to guess a number for the cell. Returns false on failure.
bool	guess(t_cell *cell)
{
	short	full_context;

	if (cell->guess != 0)
		reset(cell);
	cell->guess++;
	while (cell->guess <= 9)
	{
		full_context = *(cell->row_context)
			| *(cell->col_context)
			| *(cell->sqr_context);
		if (((full_context >> (cell->guess - 1)) & 1) == 0)
		{
			*(cell->row_context) |= 1 << (cell->guess - 1);
			*(cell->col_context) |= 1 << (cell->guess - 1);
			*(cell->sqr_context) |= 1 << (cell->guess - 1);
			return (true);
		}
		cell->guess++;
	}
	cell->guess = 0;
	return (false);
}

// Resets the guess in the cell.
void	reset(t_cell *cell)
{
	*(cell->row_context) ^= 1 << (cell->guess - 1);
	*(cell->col_context) ^= 1 << (cell->guess - 1);
	*(cell->sqr_context) ^= 1 << (cell->guess - 1);
}
