/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:10:28 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/31 20:18:24 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_list	*new_node(char *buff)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->buff = malloc(sizeof(char) * READ_BUFF);
	cpy_str(list->buff, buff);
	list->next = NULL;
	return (list);
}

void	append_node(t_list **list, char *buff)
{
	t_list	*current_node;

	if (*list == NULL)
	{
		*list = new_node(buff);
		return ;
	}
	current_node = (*list);
	while (current_node->next)
		current_node = current_node->next;
	current_node->next = new_node(buff);
}

int	get_list_len(t_list *list)
{
	t_list	*current_node;
	int		i;

	if (list == NULL)
		return (0);
	current_node = list;
	i = 1;
	while (current_node->next)
	{
		i++;
		current_node = current_node->next;
	}
	return (i);
}

void	free_list(t_list *list)
{
	if (list == NULL)
		return ;
	free_list(list->next);
	free(list->buff);
	free(list);
	list = NULL;
}

void	cat_list(char *out, t_list *list)
{
	t_list	*node;
	int		i;
	int		j;

	node = list;
	i = 0;
	while (node)
	{
		j = 0;
		while (node->buff[j])
			out[i++] = node->buff[j++];
		node = node->next;
	}
	out[i] = '\0';
}
