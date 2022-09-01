/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:54:52 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/24 22:00:02 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*list;

	if ((*begin_list) == NULL)
		*begin_list = ft_create_elem(data);
	else
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(data);
	}
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*link;

	while (--ac > 0)
		ft_list_push_back(&link, av[ac]);
	return (link);
}
