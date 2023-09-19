#include "main.h"
/**
 * cleanup - This function will Peform cleanup operations for _printf.
 * @args: This are variadic va_list to the arguments provided to _printf.
 * @output: This is the buffer_t struct.
 */
void cleanup(va_list args, buffer_t *output)
{
	va_end(args);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * run_printf - This function will read the format string for the _printf.
 * @format: Character string to print - may contain directives.
 * @output: This will be the  buffer_t struct to a buffer.
 * @args: This are the variadic va_list of arguments.
 *
 * Return: The number of characters stored to be the output.
 */
int run_printf(const char *format, va_list args, buffer_t *output)
{
	int i, wid, prec, res = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			flags = __ourprintf_handler_flags(format + i + 1, &tmp);
			wid = __ourprintf_handler_width(args, format + i + tmp + 1, &tmp);
			prec = __ourprintf_handler_precision(args, format + i + tmp + 1,
					&tmp);
			len = __ourprintf_handler_length(format + i + tmp + 1, &tmp);

			f = handle_specifiers(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				res = res + f(args, output, flags, wid, prec, len);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				res = -1;
				break;
			}
		}
		res = res + __ourprintf_memcpy(output, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	cleanup(args, output);
	return (res);
}

/**
 * _printf - This function will stdout a formatted string.
 * @format: This is the haracter string to print.
 *
 * Return: This the number of characters to be printed.
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int res;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	res = run_printf(format, args, output);

	return (res);
}
