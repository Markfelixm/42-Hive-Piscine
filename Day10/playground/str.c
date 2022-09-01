#include <stdio.h>

int main(void)
{
	int i = 0;
	//char *sentence[] = {"hi", "bye"};
	char *sentence[3];

	sentence[0] = "hi";
	sentence[1] = "ok";
	sentence[2] = "hill";


	while (sentence[i] != '\0')
	{
		printf("%s\n", sentence[i]);
		i++;
	}
}
