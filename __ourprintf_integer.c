#include "main.h"
/**
 * __ourprintf_integer - This function will print integer as a number
 * @args: This is the arguements to be printed
 * @imprint: This will  print the characters
 * Return: The printed charcaters will return.
 */
int __ourprintf_integer(va_list args, int imprint)
{
	int num = va_arg(args, int);
	int digs = 0;
	int temp = num;
	int dig;

	if (num < 0)
	{
		imprint += __ourwrite_char('-');
		num = -num;

		temp = num;
	}

	do {
		digs++;
		temp /= 10;
	} while (temp != 0);

	while (digs > 0)
	{
		int pow10 = 1;
		int k;

		for (k = 1; k < digs; k++)
		{
			pow10 *= 10;
		}
		dig = num / pow10;
		imprint += __ourwrite_char(dig + '0');
		num -= dig * pow10;
		digs--;
	}
	return (imprint);
}
