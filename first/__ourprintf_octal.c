#include "main.h"
/**
 * __ourprintf_octal - This function will print a octal number
 * @num: number of arguements to be printed
 * @imprint: the printed characters are here
 * Return: printed charcaters
 */
int __ourprintf_octal(unsigned int num, int imprint)
{
	int oct[100], k = 0, j;

	while (num != 0)
	{
		int remainder = num % 8;

		oct[k] = 48 + remainder;
		k++;
		num /= 8;
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
			__ourwrite_char(oct[j]);
			imprint++;
		}
	}
	return (imprint);
}
