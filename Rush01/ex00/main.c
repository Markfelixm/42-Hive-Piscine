/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:15:38 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/21 23:40:32 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "argvcat.h"
#include <stdlib.h>
#include "cell.h"
#include "solve.h"

// - set all static values
// - calculate length for guess array
// - returns a pointer to the guess array on success
// - returns a null pointer on error
t_cell	**parse_input(char *input, t_context *context, int *guess_count)
{
	int			i;
	t_cell		**cells;

	i = 0;
	*guess_count = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '.')
			(*guess_count)++;
		else
		{
			if (!set(context, i, (int)(input[i] - 48)))
				return (NULL);
		}
		i++;
	}
	if (*guess_count == 0)
		return (NULL);
	cells = new_cells(context, input, *guess_count);
	return (cells);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_result(char *input, t_cell **cells)
{
	int		row;
	int		col;
	int		guess;

	row = 0;
	col = 0;
	guess = 0;
	while (row < 9)
	{
		while (col < 9)
		{
			if (*input == '.')
				ft_putchar(((cells[guess++])->guess) + '0');
			else
				ft_putchar(*input);
			if (col < 8)
				ft_putchar(' ');
			input++;
			col++;
		}
		col = 0;
		ft_putchar('\n');
		row++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 10)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!run(argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}

bool	run(char **argv)
{
	t_context	*context;
	t_cell		**cells;
	char		*input;
	int			guess_count;

	guess_count = 0;
	context = new_context();
	if (context == NULL)
		return (false);
	input = argvcat(argv);
	if (input == NULL)
		return (false);
	cells = parse_input(input, context, &guess_count);
	if (cells == NULL)
		return (false);
	if (!solve(input, cells, guess_count))
		return (false);
	else if (solve(input, cells, guess_count))
		return (false);
	print_result(input, cells);
	free(input);
	free_cells(cells, guess_count);
	free(context);
	return (true);
}
