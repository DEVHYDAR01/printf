#include "main.h"
#define MAX_HEX_DIGITS 16
/**
 * __ourprintf_pointer - This function will print as a binary number
 * @args: This are the number of arguements printed
 * @imprint: This are the printed characters
 * Return: printed charcaters to be returned
 */
int __ourprintf_pointer(va_list args, int imprint)
{
	void *ptr = va_arg(args, void*);
	unsigned long num = (unsigned long) ptr;
	int digs = 0;
	int k;
	unsigned long temp = num;
	char hex_digits[MAX_HEX_DIGITS] = "0123456789abcdef";
	char hex[MAX_HEX_DIGITS];

	while (temp != 0)
	{
		digs++;
		temp /= 16;
	}

	imprint += __ourwrite_char('0');
	imprint += __ourwrite_char('x');

	if (num == 0)
	{
		imprint += __ourwrite_char('0');
	}
	else
	{
		for (k = digs - 1; k >= 0; k--)
		{
			int dig = num % 16;

			hex[k] = hex_digits[dig];
			num /= 16;
		}
		for (k = 0; k < digs; k++)
		{
			imprint += __ourwrite_char(hex[k]);
		}
	}
	return (imprint);
}
