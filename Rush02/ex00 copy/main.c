/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:54:57 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/28 20:52:47 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	t_input		*input;
	t_rushes	*rushes;

	input = parse_input();
	rushes = gen_rushes(input);
	compare_input(input, rushes);
	free(input);
	free(rushes);
	return (0);
}

t_input	*parse_input(void)
{
	t_input	*input;
	int		i;

	input = malloc(sizeof(t_input));
	input->rows = 0;
	input->cols = 0;
	input->data = malloc(sizeof(char) * BUFFER_SIZE);
	input->read_size = read(0, input->data, BUFFER_SIZE);
	if (!input->read_size)
		return (NULL);
	i = 0;
	while (input->data[i] != '\0')
	{
		if (input->data[i] == '\n')
			input->rows++;
		else if (input->rows == 0 && input->data[i] != '\n')
			input->cols++;
		i++;
	}
	return (input);
}

void	compare_input(t_input *input, t_rushes *rushes)
{
	int	matches[4];
	int	i;

	i = 0;
	if (ft_strcmp(input->data, rushes->rush00) == 0)
		matches[i++] = 0;
	if (ft_strcmp(input->data, rushes->rush01) == 0)
		matches[i++] = 1;
	if (ft_strcmp(input->data, rushes->rush02) == 0)
		matches[i++] = 2;
	if (ft_strcmp(input->data, rushes->rush03) == 0)
		matches[i++] = 3;
	if (ft_strcmp(input->data, rushes->rush04) == 0)
		matches[i++] = 4;
	matches[i] = -1;
	i = 0;
	while (matches[i] != -1)
	{
		write_result(input, matches[i]);
		if (matches[++i] != -1)
			write(1, " || ", 4);
	}
	if (matches[0] == -1)
		write(1, "none", 4);
	write(1, "\n", 1);
}

void	write_result(t_input *input, int variant)
{
	write(1, "[rush0", 7);
	ft_putnbr(variant);
	write(1, "] [", 3);
	ft_putnbr(input->cols);
	write(1, "] [", 3);
	ft_putnbr(input->rows);
	write(1, "]", 1);
}
