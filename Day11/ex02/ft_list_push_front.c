/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:14:01 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/23 19:27:38 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*list;

	if ((*begin_list) == NULL)
		*begin_list = ft_create_elem(data);
	else
	{
		list = ft_create_elem(data);
		list->next = *begin_list;
		*begin_list = list;
	}
}
