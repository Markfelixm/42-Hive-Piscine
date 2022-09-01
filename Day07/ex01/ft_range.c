/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:26:02 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/18 19:58:37 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	diff;
	int	i;

	if (min >= max)
		return ((void *)0);
	else
		diff = max - min;
	range = (int *)malloc(sizeof(*range) * diff);
	if (range == NULL)
		return (0);
	i = 0;
	while (i < diff)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
