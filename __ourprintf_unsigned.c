#include "main.h"
/**
 * __ourprintf_unsigned - This function will print an unsigned number
 * @num: number of arguements to be printed
 * @imprint: the printed characters to be
 * Return: printed charcaters will return
 */
int __ourprintf_unsigned(unsigned int num, int imprint)
{
	int digs = 0;
	unsigned int temp = num;

	do {
		digs++;
		temp /= 10;
	} while (temp != 0);

	if (num == 0)
	{
		__ourwrite_char('0');
		imprint++;
	}
	else
	{
		char unsigned_str[11];
		int k = 0;

		while (num != 0)
		{
			unsigned_str[k] = (num % 10) + '0';
			num /= 10;
			k++;
		}
		for (k = digs - 1; k >= 0; k--)
		{
			__ourwrite_char(unsigned_str[k]);
			imprint++;
		}
	}
	return (imprint);
}
