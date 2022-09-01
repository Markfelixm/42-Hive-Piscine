#include "ft_btree.h"
#include <stdio.h>

t_btree	*btree_create_node(void *item);

void	say(void *data)
{
	printf("%s\n", data);
}

int	main(int argc, char **argv)
{
	t_btree	*tree;

	tree = NULL;
	if (argc == 8)
	{
		tree = btree_create_node(argv[1]);
		tree->left = btree_create_node(argv[2]);
		tree->right = btree_create_node(argv[3]);
		tree->left->left = btree_create_node(argv[4]);
		tree->left->right = btree_create_node(argv[5]);
		tree->right->left = btree_create_node(argv[6]);
		tree->right->right = btree_create_node(argv[7]);
	}

	btree_apply_suffix(tree, &say);
	return (0);
}
