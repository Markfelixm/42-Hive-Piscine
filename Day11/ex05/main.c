#include "ft_list.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_list *list;

	list = ft_list_push_params(argc, argv);
	printf("______first to fourth element______\n");
	printf("%s\n", list->data);
	printf("%p\n", list->next);
	printf("%s\n", list->next->data);
	printf("%p\n", list->next->next);
	printf("%s\n", list->next->next->data);
	printf("%p\n", list->next->next->next);
	printf("%s\n", list->next->next->next->data);
	printf("%p\n", list->next->next->next->next);
	return (0);
}
