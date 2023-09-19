#include "main.h"
/**
 * __ourprintf_width - This function will tores leading
 * spaces to buffer for a width modifier.
 * @output: This is our buffer_t struct containing a character array.
 * @printed: The current number of characters already printed to output
 * to a given number specifier.
 * @flags: our flag modifiers.
 * @wid: our width modifier.
 *
 * Return: The number of bytes stored to the buffer is returned.
 */
unsigned int __ourprintf_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int res = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		for (wid -= printed; wid > 0;)
			res = res + __ourprintf_memcpy(output, &width, 1);
	}

	return (res);
}

/**
 * __ourprintf_string_width - This function will hold leading spaces to a buffer for a width modifier.
 * @output: our buffer_t struct containing a character array.
 * @flags: our flag modifiers.
 * @wid: This is the width modifier.
 * @prec: This isprecision modifier.
 * @size: This is the size of the string.
 *
 * Return: The number of bytes stored to the buffer is returned.
 */
unsigned int __ourprintf_string_width(buffer_t *output,
		unsigned char flags, int wid, int prec, int size)
{
	unsigned int res = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		wid -= (prec == -1) ? size : prec;
		for (; wid > 0; wid--)
			res = res + __ourprintf_memcpy(output, &width, 1);
	}

	return (res);
}

/**
 * __ourprintf_neg_width - This function will hold
 * trailing spaces to a buffer for a '-' flag.
 * @output: this is the variadic buffer_t struct
 * containing a character array.
 * @printed: The is the current number of bytes already held to output
 * for a given specifier.
 * @flags: our flag modifiers.
 * @wid: our width modifier.
 *
 * Return: The number of bytes stored to the buffer is returned.
 */
unsigned int __ourprintf_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int res = 0;
	char width = ' ';

	if (NEG_FLAG == 1)
	{
		for (wid -= printed; wid > 0; wid--)
			res = res + __ourprintf_memcpy(output, &width, 1);
	}

	return (res);
}
