#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	printf("%d vs %d\n", strcmp("aa", "bb"), ft_strcmp("aa", "bb"));
	printf("%d vs %d\n", strcmp("bb", "aa"), ft_strcmp("bb", "aa"));
	printf("%d vs %d\n", strcmp("ab", "bb"), ft_strcmp("ab", "bb"));
	printf("%d vs %d\n", strcmp("ba", "bb"), ft_strcmp("ba", "bb"));
	printf("%d vs %d\n", strcmp("AA", "aa"), ft_strcmp("AA", "aa"));
	printf("%d vs %d\n", strcmp("BA", "aa"), ft_strcmp("AB", "aa"));
	printf("%d vs %d\n", strcmp("aa", "AA"), ft_strcmp("aa", "AA"));

	return (0);
}
