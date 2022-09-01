/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:33:30 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/21 21:52:59 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H
# include <stdbool.h>
# include "cell.h"

// Moves the given index to the next position in the input that is not a dot,
// going backwards if 'backtrack' is true.
// Returns false if the index ends out of bounds.
bool	seek_next_index(int *i, char *input, bool backtrack);

// TODO this somehow gets J to go -1 at some point
// Attempts to solve the sudoku, returns false on failure.
bool	solve(char *input, t_cell **cells, int guess_count);

#endif