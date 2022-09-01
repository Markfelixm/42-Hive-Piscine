#include "ft_btree.h"
#include <stdio.h>

int	main(void)
{
	t_btree	*node;

	node = btree_create_node("fourtytwo");
	printf("item: %s\n", node->item);
	printf("left: %p\n", node->left);
	printf("right: %p\n", node->right);
	printf("address: %p\n", node);
	return (0);
}
