#include "main.h"
/**
 * __ourprintf_binary - This function will print a binary number
 * @num: This are the number arguements to be printed
 * @imprint: The printed characters to be printed
 * Return: printed charcaters returned
 */
int __ourprintf_binary(unsigned int num, int imprint)
{
	int binary[32] = {0};
	int k = 0;

	if (num == 0)
	{
		__ourwrite_char('0');
		imprint++;
		return (imprint);
	}

	while (num > 0)
	{
		binary[k] = num % 2;
		num /= 2;
		k++;
	}

	while (k > 0)
	{
		k--;
		__ourwrite_char('0' + binary[k]);
		imprint++;
	}

	return (imprint);
}
