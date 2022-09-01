/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:36:50 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/21 23:24:16 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include <stdlib.h>

// Initializes and returns the full context data.
t_context	*new_context(void)
{
	t_context	*context;

	context = malloc(sizeof(t_context));
	if (!context)
		return (NULL);
	context->rows = context_array();
	context->cols = context_array();
	context->sqrs = context_array();
	return (context);
}

// Initializes and returns a sub-context array?
short	*context_array(void)
{
	short	*arr;
	int		i;

	arr = malloc(sizeof(short [9]));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < 9)
		arr[i++] = 0;
	return (arr);
}

// Sets a static value into context, returns false on failure.
bool	set(t_context *ctx, int index, int value)
{
	short	full_context;
	int		row;
	int		col;
	int		sqr;

	full_context = 0;
	row = index / 9;
	col = index % 9;
	sqr = 3 * (row / 3) + (col / 3);
	if (((full_context >> (value - 1)) & 1) == 0)
	{
		ctx->rows[row] |= 1 << (value - 1);
		ctx->cols[col] |= 1 << (value - 1);
		ctx->sqrs[sqr] |= 1 << (value - 1);
		return (true);
	}
	return (false);
}
