/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:08:27 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/21 23:22:29 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "context.h"
# include "cell.h"

// - set all static values 
// - calculate length for guess array
// - returns a pointer to the guess array on success
// - returns a null pointer on error
t_cell	**parse_input(char *input, t_context *context, int *guesses_count);

// - loop through argv
// - print every static number
// - print the value at guess and increment guess pointer for every dot
void	print_result(char *input, t_cell **cells);

bool	run(char **argv);

#endif
