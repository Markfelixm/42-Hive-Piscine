/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:15:38 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/21 18:26:09 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "argvcat.h"
#include "argvcat.c"
#include <stdio.h>
#include <stdlib.h>

// Initializes and returns a sub-context array?
short *context_array()
{
	short	*arr;
	int		i;

	arr = malloc(sizeof(short[9]));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < 9)
		arr[i++] = 0;
	return (arr);
}

short		get_cell_context(t_context *ctx, int row, int col, int sq)
{
	return (ctx->rows[row] | ctx->columns[col] | ctx->squares[sq]);
}

t_guesses	*new_guesses(int length)
{
	int	i;
	t_guesses *guesses;

	i = 0;
	guesses = malloc(sizeof(t_guesses));
	if (guesses == NULL)
		return (NULL);
	guesses->length = length;
	guesses->guesses = malloc(sizeof(int) * length);
	if (guesses->guesses == NULL)
		return (NULL);
	while (i < length)
		guesses->guesses[i++] = 0;
	return (guesses);
}

// Initializes and returns the full context data.
t_context *new_context(void)
{
	t_context	*context;

	context = malloc(sizeof(t_context));
	if (!context)
		return (NULL);
	context->rows = context_array();
	context->columns = context_array();
	context->squares = context_array();
	return (context);
}

int	get_row(int index)
{
	return (index / 9);
}

int get_column(int index)
{
	return (index % 9);
}

int	get_square(int row, int column)
{
	return (3 * (row / 3) + (column / 3));
}

// Attempts to set given value in a given index, returning false on failure.
bool	try_set_value(t_context *ctx, int index, int value)
{
	short	cell_context;
	int		shift;
	int		row;
	int		col;
	int		sq;

	row = get_row(index);
	col = get_column(index);
	sq = get_square(row, col);
	cell_context = get_cell_context(ctx, row, col, sq);
	shift = 1 << (value - 1);
	if (((cell_context >> (value - 1)) & 1) == 0)
	{
		ctx->rows[row] |= shift;
		ctx->columns[col] |= shift;
		ctx->squares[sq] |= shift;
		return (true);
	}
	return (false);
}

int	try_increment_value(t_context *ctx, int index, int value)
{
	value++;

	while (value <= 9)
	{
		printf("%i\n", value);
		if (!try_set_value(ctx, index, value))
			value++;
		else
		{
			printf("SET: %i\n", value);
			return (value);
		}
	}
	return (0);
}

// Unsets the given value in the given index.
void	unset(t_context *ctx, int index, int value)
{
	int		shift;
	int		row;
	int		col;
	int		sq;

	row = get_row(index);
	col = get_column(index);
	sq = get_square(row, col);
	shift = 1 << (value - 1);
	ctx->rows[row] ^= shift;
	ctx->columns[col] ^= shift;

	ctx->squares[sq] ^= shift;
}

// Moves the given index to the next position in the input that is not a dot,
// going backwards if 'backtrack' is true.
// Returns false if the index ends out of bounds.
bool	seek_next_index(int *i, char *input, bool backtrack)
{
	// We dont want to auto increment if i[0] is a dot;
	printf("SEEK FROM %i\n", *i);
	printf("\nbacktrack: %i\n", (int)backtrack);
	if (backtrack)
		(*i)--;
	else
		(*i)++;
	while (input[*i] != '.')
	{
		printf("\ninwhile: %i\n", *i);
		if (backtrack)
		{
			(*i)--;
		}
		else
		{
			(*i)++;
		}
	}
	printf("\nafterseek: %i\n", *i);
	if ((*i) < 0 || input[*i] == '\0')
		return (false);
	return (true);
}

// TODO this somehow gets J to go -1 at some point
// Attempts to solve the sudoku, returns false on failure.
bool	solve(char *input, t_context *context, t_guesses *guesses)
{
	int		i;
	int		j;
	int		guess;

	i = 0;
	j = 0;
	guess = 0;

	if (input[i] != '.')
	{
		if(!seek_next_index(&i, input, false))
				return (false);
	}
	printf("\nFirst guess idx: %i\n", i);
	while (j >= 0 && j <= guesses->length)
	{
		guess = try_increment_value(context, i, guesses->guesses[j]); // FIXME: modify guess arr in place
		if (guess != 0)
		{
			guesses->guesses[j] = guess;
			printf("\nJ: %i\n", j);
			printf("\nG: %i\n", guesses->length);
			if (j >= (guesses->length - 1))
				return (true);
			if(!seek_next_index(&i, input, false))
				return (false);
			j++;
		}
		else
		{
			if(!seek_next_index(&i, input, true))
				return (false);
			if (j != 0)
				guesses->guesses[j] = 0;
			j--;
			unset(context, i, guesses->guesses[j]); // FIXME: modify guess arr in place
		}
	}
	printf("THIS SHOULD NEVER HAPPEN !!! %i, %i", i, j); // TODO: remove this
	return (false);
}

// - set all static values
// - calculate length for guess array
// - returns a pointer to the guess array on success
// - returns a null pointer on error
t_guesses	*parse_input(char *input, t_context *context)
{
	int			i;
	int			guesses_count;

	i = 0;
	guesses_count = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '.')
			guesses_count++;
		else
		{
			if (!try_set_value(context, i, (int)(input[i] - 48)))
				return (NULL);
		}
		i++;
	}
	return (new_guesses(guesses_count));
	return (NULL);
}

void	print_result(char *input, t_guesses *guesses)
{
	int	i;
	int guess;
	char c;
	int row;

	i = 0;
	guess = 0;
	c = 'x';
	row = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '.')
		{
			c = guesses->guesses[guess] + '0';
			guess++;
			write(1, &c, 1);
		}
		else
		{
			write(1, &input[i], 1);
		}
		i++;
		row++;
		if (row >= 9)
		{
			row = 0;
			c = '\n';
			write(1, &c, 1);
		}
	}
}

int	main(int argc, char **argv)
{
	t_context	*context;
	t_guesses	*guesses;
	char		*input;

	if (argc != 10)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	context = new_context();
	if (context == NULL)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	input = argvcat(argv);
	if (input == NULL)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	guesses = parse_input(input, context);
	if (guesses == NULL)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!solve(input, context, guesses))
	{
		write(1, "Fail\n", 5); // FIXME: Change to Error
		return (0);
	}
	print_result(input, guesses);
	free(input);
	free(guesses->guesses);
	free(guesses);
	free(context);
	return (0);
}

// "...26.7.1" "68..7..9." "19...45.." "82.1...4." "..46.29.." ".5...3.28" "..93...74" ".4..5..36" "7.3.18..."
// "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......."

//
