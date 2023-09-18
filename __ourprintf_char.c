#include "main.h"
/**
 * __ourprintf_char - This function will print a binary number
 * @args: This is the arguements to be used
 * @imprint: the printed characters
 * Return: printed charcaters
 */
int __ourprintf_char(va_list args, int imprint)
{
	int actor = va_arg(args, int);

	__ourwrite_char(actor);
	return (imprint + 1);
}
