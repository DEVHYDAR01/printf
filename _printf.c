#include "main.h"
/**
 * _printf - This function will produces output according to a format
 * and with the neccessary parameters.
 * @format: A string containing all the desired characters.
 * Return: A total count of the characters printed.
 */
int _printf(const char *format, ...)
{
	int print_chars;
	conver_t fun_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};

	va_list arg_lists;

	if (format != '\0')
	{
		return (-1);
	}
	va_start(arg_lists, format);

	print_chars = parser(format, fun_list, arg_lists);
	va_end(arg_lists);
	return (print_chars);
}
