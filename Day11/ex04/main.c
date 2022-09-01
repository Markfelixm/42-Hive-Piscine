#include "ft_list.h"
#include <stdio.h>

t_list	*ft_create_elem(void *data);
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_push_front(t_list **begin_list, void *data);

int	main(void)
{
	t_list	*list;
	t_list	*last;
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "This.";
	str2 = "thaT!";
	str3 = "these?";
	list = ft_create_elem(str1);
	ft_list_push_front(&list, str2);
	ft_list_push_front(&list, str3);
	printf("______SETUP______\n");
	printf("%s\n", list->data);
	printf("%p\n", list->next);
	printf("%s\n", list->next->data);
	printf("%p\n", list->next->next);
	printf("%s\n", list->next->next->data);
	printf("%p\n", list->next->next->next);
	printf("______CHECK______\n");
	last = ft_list_last(list);
	printf("%s\n", last->data);
	printf("%p\n", last->next);
	return (0);
}
