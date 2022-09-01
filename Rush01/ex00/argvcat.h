/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argvcat.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:59:45 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/21 19:48:01 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGVCAT_H
# define ARGVCAT_H
# include <stdbool.h>

// Returns true if the given character is valid for the sudoku input.
bool	is_valid(char c);

// Parses the given string to the output adding the given terminator to end
// of string. Returns false if the input string is invalid for the sudoku.
bool	parse_str(char *str, char *output, bool terminate);

// Concatenates argv into a single null terminated string, delimiting each
// section with a newline and checking for valid sudoku characters.
// Returns a NULL pointer on error.
char	*argvcat(char **argv);

#endif