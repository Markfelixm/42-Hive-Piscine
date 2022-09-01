/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:32:00 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/23 20:59:54 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*node;
	int		size;

	if ((begin_list) == NULL)
		return (0);
	node = begin_list;
	size = 1;
	while (node->next != NULL)
	{
		node = node->next;
		size++;
	}
	return (size);
}
