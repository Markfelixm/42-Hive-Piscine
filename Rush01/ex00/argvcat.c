/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argvcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:40:12 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/21 23:24:23 by tjaasalo         ###   ########.fr       */
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
// Parses the given string to the output adding the given terminator to end
// of string. Returns false if the input string is invalid for the sudoku.
bool	parse_str(char *str, char *output, bool terminate)
{
	int	i;

	i = 0;
	while (i <= 8)
	{
		if (!is_valid(str[i]))
			return (false);
		*output = str[i++];
		output++;
	}
	if (str[i])
		return (false);
	if (terminate)
		*output = '\0';
	return (true);
}

char	*argvcat(char **argv)
{
	char	*output;
	int		i;

	i = 0;
	output = malloc(sizeof(char) * (9 * 9 + 1));
	if (output == NULL)
		return (NULL);
	argv++;
	while (i < 8)
	{
		if (!parse_str(*argv, (output + i * 9), false))
			return (NULL);
		argv++;
		i++;
	}
	if (!parse_str(*argv, (output + i * 9), true))
		return (NULL);
	return (output);
}
