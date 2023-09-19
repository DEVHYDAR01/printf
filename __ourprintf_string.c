#include "main.h"
/**
 * __ourprintf_string - This function will print a string
 * @args: This are the number of arguements
 * @imprint: The will print characters
 * Return: printed charcaters to be printed
 */
int __ourprintf_string(va_list args, int imprint)
{
	char *str = va_arg(args, char *);

	while (*str != '\0')
	{
		__ourwrite_char(*str);
		imprint++;
		str++;
	}
	return (imprint);
}
