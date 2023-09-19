#include <stdio.h>
/**
 *
 * print a to z except q and e.
 *
 */
int main(void)
{
	int i;

	for (i = 'a'; i <= 'z'; i++)
	{
		if (i == 'e')
		{
			continue;
		}
		if (i == 'q')
		{
			continue;
		}
		printf("%c", i);
	}
	return (0);
}
