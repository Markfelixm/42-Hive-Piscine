#include <stdio.h>
#include "match.c"

int	match(char *s1, char *s2);

// int	main(int argc, char **argv)
// {
// 	int	bool;

// 	if (argc != 3)
// 		return (0);
// 	bool = match(argv[1], argv[2]);
// 	printf("matched: %d\n", bool);
// 	return (0);
// }
int	main(void)
{
	int	bool;
	char	*haystack = "abcd";
	char	*needle = "*c*";

	bool = match(haystack, needle);
	printf("matched: %d\n", bool);
	return (0);
}
