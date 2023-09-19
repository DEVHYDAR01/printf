#include "main.h"
/**
 * _printf - This function will receive a string
 * and all the necessary parameters to be printed as a formatted string
 * @format: This is the string containing all of the desired characters
 * Return: The total count of the characters that are printed.
 */
int _printf(const char *format, ...)
{
	int imprint = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			imprint = selector(format, args, imprint);
			format++;
		}
		else
		{
			__ourwrite_char(*format);
			imprint++;
			format++;
		}
	}
	va_end(args);
	return (imprint);
}
