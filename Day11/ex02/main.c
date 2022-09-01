#include "ft_list.h"
#include <stdio.h>

int	main(void)
{
	t_list	*list;
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "This.";
	str2 = "thaT!";
	str3 = "these?";
	list = NULL;
	list = ft_create_elem(str1);
	printf("_______Initial______\n");
	printf("%s\n", list->data);
	printf("%p\n", list->next);
	ft_list_push_front(&list, str2);
	printf("_______firstcall______\n");
	printf("%s\n", list->data);
	printf("%p\n", list->next);
	printf("%s\n", list->next->data);
	printf("%p\n", list->next->next);
	ft_list_push_front(&list, str3);
	printf("_______secondcall______\n");
	printf("%s\n", list->data);
	printf("%p\n", list->next);
	printf("%s\n", list->next->data);
	printf("%p\n", list->next->next);
	printf("%s\n", list->next->next->data);
	printf("%p\n", list->next->next->next);
	return (0);
}
