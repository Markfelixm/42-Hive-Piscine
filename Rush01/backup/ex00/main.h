/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:08:27 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/21 16:45:03 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_context {
	short	*rows;
	short	*columns;
	short	*squares;
}	t_context;
typedef struct s_cell {
	int	row;
	int	col;
	int	sq;
	int value;
}	t_cell;
typedef struct s_guesses {
	int	*guesses;
	int	length;
}	t_guesses;
t_guesses	*new_guesses(int length);
short		*context_array(void);
t_context	*new_context(void);
short		get_cell_context(t_context *ctx, int row, int col, int sq);
int			square(int row, int col);
bool		try_set_value(t_context *ctx, int index, int value);
void		unset(t_context *ctx, int index, int value);
// Attempts to increment a previously set value, returns false on failure.
int		try_increment_value(t_context *ctx, int index, int value);

// - set all static values 
// - calculate length for guess array
// - returns a pointer to the guess array on success
// - returns a null pointer on error
t_guesses *parse_input(char *input, t_context *context);

bool	solve(char *input, t_context *context, t_guesses *guesses);
// - loop through argv
// - print every static number
// - print the value at guess and increment guess pointer for every dot
void	print_result(char *input, t_guesses *guesses);

#endif