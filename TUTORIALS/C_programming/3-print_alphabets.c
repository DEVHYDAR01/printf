#include <stdio.h>
/**
 *
 * prints a - z and A - Z
 *
 */
int main(void)
{

	int i, j;

	for (i = 'a'; i <= 'z'; i++)
	{
	
		printf("%c", i);
	}

	for (j = 'A'; j <= 'Z'; j++)
	{
	
		printf("%c", j);
	}
	printf("\n");
	return (0);
}
