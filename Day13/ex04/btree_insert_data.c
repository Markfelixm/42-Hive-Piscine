/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:34:45 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/26 20:40:59 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_insert_node(
	t_btree *root, void *item, int (*cmpf)(void *, void *))
{
	if (!root)
		return (btree_create_node(item));
	if (cmpf(item, root->item) >= 0)
		root->right = btree_insert_node(root->right, item, cmpf);
	else
		root->left = btree_insert_node(root->left, item, cmpf);
}

void	btree_insert_data(
	t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	btree_insert_node(*root, item, cmpf);
}
