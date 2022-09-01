/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:33:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/21 23:23:45 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

//	Moves the given index to the next position in the input that is not a dot,
//	going backwards if 'backtrack' is true.
//	Returns false if the index ends out of bounds.
bool	seek_next_index(int *i, char *input, bool backtrack)
{
	if (backtrack)
		(*i)--;
	else
		(*i)++;
	while (input[*i] != '.')
	{
		if (backtrack)
		{
			(*i)--;
		}
		else
		{
			(*i)++;
		}
	}
	if ((*i) < 0 || input[*i] == '\0')
		return (false);
	return (true);
}

//	TODO this somehow gets J to go -1 at some point
//	Attempts to solve the sudoku, returns false on failure.
bool	solve(char *input, t_cell **cells, int guess_count)
{
	int		i;
	int		cell;

	i = 0;
	cell = 0;
	if (input[i] != '.' && !seek_next_index(&i, input, false))
		return (false);
	while (cell >= 0 && cell <= guess_count)
	{
		if (guess(cells[cell]))
		{
			if (cell >= (guess_count - 1))
				return (true);
			if (!seek_next_index(&i, input, false))
				return (false);
			cell++;
		}
		else
		{
			if (!seek_next_index(&i, input, true))
				return (false);
			cell--;
		}
	}
	return (false);
}
