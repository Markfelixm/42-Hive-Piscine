/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argvcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:40:12 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/21 15:47:15 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argvcat.h"
#include <stdlib.h>

// Returns true if the given character is valid for the sudoku input.
bool	is_valid(char c)
{
	if (c != '.' && (c < '0' || c > '9'))
		return (false);
	return (true);
}

// bool	parse_str(char *str, char *output, int *i);
// Parses the given string to the output at row.
// Returns false if the input string is invalid for the sudoku.
bool	parse_str(char *str, char *output, int row)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (!is_valid(str[i]))
			return (false);
		output[row * 9 + i] = str[i];
		i++;
	}
	if (str[i])
		return (false);
	return (true);
}

// Concatenates argv into a single null terminated string checking for valid sudoku
// characters.
// Returns a NULL pointer on error.
char	*argvcat(char **argv)
{
	char	*output;
	int		row;

	row = 0;
	output = malloc(sizeof(char) * (9 * 9 + 1));
	if (output == NULL)
		return (NULL);
	argv++;
	while (row < 9)
	{
		if (!parse_str(*argv, output, row))
			return (NULL);
		argv++;
		row++;
	}
	output[row * 9 + 1] = '\0';
	return (output);
}
