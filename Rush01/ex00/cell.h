/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:51:40 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/21 23:19:31 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELL_H
# define CELL_H
# include <stdbool.h>
# include "context.h"

//	Cell in the puzzle containing our guessed value, and pointers to each
//	context (row, column, square) of the cell.
typedef struct s_cell {
	int		guess;
	short	*row_context;
	short	*col_context;
	short	*sqr_context;
}	t_cell;

//	Returns a pointer to a new cell, or NULL on error.
t_cell	*new_cell(t_context *ctx, int index);

//	Returns an array of new cells with the given length.
t_cell	**new_cells(t_context *context, char *input, int length);

void	free_cells(t_cell **cells, int length);

//	Tries to guess a number for the cell, setting the smallest possible
//	valid guess that is higher than it's current. Returns false if no 
//	valid guess could be made.
bool	guess(t_cell *cell);

//	Resets the guess in the cell.
void	reset(t_cell *cell);

#endif