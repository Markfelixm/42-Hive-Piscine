#include "ft_list.h"
#include <stdio.h>

void	ft_list_push_front(t_list **begin_list, void *data);

// int	ft_list_size(t_list *begin_list)
// {
// 	int	size;

// 	size = 0;
// 	if ((begin_list) == NULL)
// 		return (0);
// 	while (begin_list[size].next != NULL)
// 		size++;
// 	return (size);
// }

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
	ft_list_push_front(&list, str2);
	ft_list_push_front(&list, str3);
	ft_list_push_front(&list, str2);
	ft_list_push_front(&list, str2);
	ft_list_push_front(&list, str2);
	ft_list_push_front(&list, str2);
	ft_list_push_front(&list, str2);
	ft_list_push_front(&list, str3);
	printf("_______five______\n");

	printf("size: %i\n", ft_list_size(list));
	return (0);
}
