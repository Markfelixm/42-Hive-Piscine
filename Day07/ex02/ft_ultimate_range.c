/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:50:58 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/18 19:58:40 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	diff;
	int	i;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	diff = max - min;
	*range = (int *)malloc(sizeof(int) * diff);
	if (range == NULL)
		return (0);
	i = 0;
	while (i < diff)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (diff);
}
