#include "ft_list.h"
#include <stdio.h>

int	main(void)
{
	t_list	*elem;
	char	*str;

	str = "This.";
	elem = ft_create_elem(str);
	printf("%s\n", elem->data);
	printf("%p\n", elem->next);
}
