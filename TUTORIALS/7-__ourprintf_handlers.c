#include "main.h"
/**
 * __ourprintf_handler_flags - function to matche flags with corresponding values.
 * @flag: This is a  pointer to a potential string of flags.
 * @index: it is anindex counter for the original format string.
 *
 * Return: If flag character are matched a corresponding value.
 * Otherwise 0.
 */
unsigned char __ourprintf_handler_flags(const char *flag, char *index)
{
	int i, j;
	unsigned char res = 0;
	flags_t flags[] = {
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEG},
		{0, 0}
	};

	for (i = 0; flag[i]; i++)
	{
		for (j = 0; flags[j].flag != 0; j++)
		{
			if (flag[i] == flags[j].flag)
			{
				(*index)++;
				if (res == 0)
					res = flags[j].value;
				else
					res |= flags[j].value;
				break;
			}
		}
		if (flags[j].value == 0)
			break;
	}

	return (res);
}
/**
 * __ourprintf_handler_length - function matches length modifiers
 * with their corresponding value.
 * @modifier: This is pointer to a potential length modifier.
 * @index: it is an index counter for the original format string.
 *
 * Return: If a lenth modifier is matched its corresponding value.
 * Otherwise 0.
 */
unsigned char __ourprintf_handler_length(const char *modifier, char *index)
{
	if (*modifier == 'h')
	{
		(*index)++;
		return (SHORT);
	}

	else if (*modifier == 'l')
	{
		(*index)++;
		return (LONG);
	}

	return (0);
}
/**
 * __ourprintf_handler_width - function matches a width
 * modifier with its corresponding value.
 * @args: The function va_list of arguments.
 * @modifier: This is a pointer to a potential width modifier.
 * @index: it is an index counter for the original format string.
 *
 * Return: If a width modifier is matched - its value.
 * Otherwise 0.
 */
int __ourprintf_handler_width(va_list args, const char *modifier, char *index)
{
	int value = 0;

	while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}

	return (value);
}
/**
 * __ourprintf_handler_precision - function that matches
 * a precision modifier withits corresponding value.
 * @args: our variadic va_list of arguments.
 * @modifier: our pointer to a potential precision modifier.
 * @index: it is an index counter for the original format string.
 *
 * Return: If a precision modifier is matched its value.
 * If the precision modifier is empty, zero, or negative 0.
 * Otherwise -1.
 */
int __ourprintf_handler_precision(va_list args, const char *modifier, char *index)
{
	int value = 0;

	if (*modifier != '.')
		return (-1);

	modifier++;
	(*index)++;

	if ((*modifier <= '0' || *modifier > '9') &&
		 *modifier != '*')
	{
		if (*modifier == '0')
			(*index)++;
		return (0);
	}

	while ((*modifier >= '0' && *modifier <= '9') ||
		   (*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}

	return (value);
}
/**
 * handle_specifiers - funtion to matches a conversion specifier with
 * a corresponding conversion function.
 * @specifier: it is a pointer to a potential conversion specifier.
 *
 * Return: If a conversion function is matched a pointer to the function.
 * Otherwise - NULL.
 */
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char)
{
	int i;
	transform_t transformers[] = {
		{'c', __ourprintf_char},
		{'s', __ourprintf_string},
		{'d', __ourprintf_decimal},
		{'i', __ourprintf_decimal},
		{'%', __ourprintf_percent},
		{'b', __ourprintf_binary},
		{'u', __ourprintf_unsigned},
		{'o', __ourprintf_octal},
		{'x', __ourprintf_hexadecimal},
		{'X', __ourprintf_HEX},
		{'S', __ourprintf_STRING},
		{'p', __ourprintf_pointer},
		{'r', __ourprintf_r},
		{'R', __ourprintf_R},
		{0, NULL}
	};

	for (i = 0; transformers[i].func; i++)
	{
		if (transformers[i].specifier == *specifier)
			return (transformers[i].func);
	}

	return (NULL);
}
