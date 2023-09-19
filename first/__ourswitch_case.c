#include "main.h"
/**
 * selector - This function will select the appropriate specifiers
 * @args: number of arguements to be printed
 * @imprint: the printed characters are here
 * @format: This is the format specifier
 * Return: printed charcaters.
 */
int selector(const char *format, va_list args, int imprint)
{
	switch (*format)
	{
		case 'd':
		case 'i':
			imprint = __ourprintf_integer(args, imprint);
			break;
		case 'c':
			__ourwrite_char(va_arg(args, int));
			imprint++;
			break;
		case 's':
			imprint = __ourprintf_string(args, imprint);
			break;
		case '%':
			__ourwrite_char('%');
			imprint++;
			break;
		case 'b':
			imprint = __ourprintf_binary(va_arg(args, unsigned int), imprint);
			break;
		case 'x':
		case 'X':
			imprint = _x(va_arg(args, unsigned int), imprint, (*format == 'X') ? 1 : 0);
			break;
		case 'o':
			imprint = __ourprintf_octal(va_arg(args, unsigned int), imprint);
			break;
		case 'u':
			imprint = __ourprintf_unsigned(va_arg(args, unsigned int), imprint);
			break;
		case 'r':
			imprint = __ourprintf_reverse(args, imprint);
			break;
		case 'p':
			imprint = __ourprintf_pointer(args, imprint);
			break;
		default:
			break;
	}
	return (imprint);
}
