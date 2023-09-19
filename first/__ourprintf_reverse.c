#include "main.h"
/**
 * __ourprintf_reverse - This function will prints in reverse number
 * @args: This is the number of the arguements to be printed
 * @imprint: The printed characters to be printed
 * Return: printed charcaters will be returned
 */
int __ourprintf_reverse(va_list args, int imprint)
{
	char *str = va_arg(args, char *);
	int length = 0, k;

	while (str[length])
	{
		length++;
	}

	for (k = length - 1; k >= 0; k--)
	{
		__ourwrite_char(str[k]);
		imprint++;
	}

	return (imprint);
}
