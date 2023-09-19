#include "main.h"
/**
 * _x - This will print a hex number
 * @num: number arguements to be printed
 * @imprint: the printed characters imprints
 * @uppercase: the uppercase equivalent ok
 * Return: printed charcaters returned
 */
int _x(unsigned int num, int imprint, int uppercase)
{
	int hex[100], k = 0, j;

	while (num != 0)
	{
		int remainder = num % 16;

		if (remainder < 10)
		{
			hex[k] = 48 + remainder;
		}
		else
		{
			if (uppercase)
			{
				hex[k] = 65 + (remainder - 10);
			}
			else
			{
				hex[k] = 97 + (remainder - 10);
			}
		}
		k++;
		num /= 16;
	}
	if (k == 0)
	{
		__ourwrite_char('0');
		imprint++;
	}
	else
	{
		for (j = k - 1; j >= 0; j--)
		{
			__ourwrite_char(hex[j]);
			imprint++;
		}
	}
	return (imprint);
}
