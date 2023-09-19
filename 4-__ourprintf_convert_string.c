#include "main.h"
/**
 * __ourprintf_string - This function will onverts an argument
 * to a string and stores it to a buffer contained in a struct.
 * @args: This the variadic va_list pointing to the argument to be converted.
 * @flags: our flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 * @len: our length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer to be returned.
 */
unsigned int __ourprintf_string(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)";
	int size;
	unsigned int res = 0;

	(void)flags;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (__ourprintf_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	res = res + __ourprintf_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	while (*str != '\0' && prec > 0)
	{
		res = res + __ourprintf_memcpy(output, str, 1);
		prec--;
		str++;
	}

	res = res + __ourprintf_neg_width(output, res, flags, wid);

	return (res);
}
/**
 * __ourprintf_STRING - This function will converts
 * an argument to a string andstores it
 * to a buffer contained in a struct.
 * @args: This is our variadic va_list pointing to the argument to be converted.
 * @flags: our flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 * @len: our length modifier.
 * @output: this is thebuffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer is returned.
 *
 * Description: This the Non-printable characteres (ASCII values < 32 or >= 127)
 * are stored as \x followed by the ASCII code value in hex.
 */
unsigned int __ourprintf_STRING(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)", *hex = "\\x", zero = '0';
	int size, index;
	unsigned int res = 0;

	(void)len;
	str = va_arg(args, char *);
	if (str == NULL)
		return (__ourprintf_memcpy(output, null, 6));

	for (size = 0; str[size];)
		size++;

	res = res + __ourprintf_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	for (index = 0; *(str + index) != '\0' && index < prec; index++)
	{
		if (*(str + index) < 32 || *(str + index) >= 127)
		{
			res = res + __ourprintf_memcpy(output, hex, 2);
			if (*(str + index) < 16)
				res = res + __ourprintf_memcpy(output, &zero, 1);
			res = res + __ourprintf_ubase(output, *(str + index),
						 "0123456789ABCDEF", flags, 0, 0);
			continue;
		}
		res = res + __ourprintf_memcpy(output, (str + index), 1);
	}

	res = res + __ourprintf_neg_width(output, res, flags, wid);

	return (res);
}

/**
 * __ourprintf_r - This function will reverses a string and stores it
 * to a buffer contained in a struct.
 * @args: This is the variadic va_list
 * pointing to the string to be reversed.
 * @flags: our flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 * @len: our length modifier.
 * @output: our buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer is returned.
 */
unsigned int __ourprintf_r(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)";
	int size, end, i;
	unsigned int res = 0;

	(void)flags;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (__ourprintf_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	res = res + __ourprintf_string_width(output, flags, wid, prec, size);

	end = size - 1;
	prec = (prec == -1) ? size : prec;
	for (i = 0; end >= 0 && i < prec; i++)
	{
		res = res + __ourprintf_memcpy(output, (str + end), 1);
		end--;
	}

	res = res + __ourprintf_neg_width(output, res, flags, wid);

	return (res);
}

/**
 * __ourprintf_R - This function will onvert a string to ROT13 and stores
 * it to a buffer contained in a struct.
 * @args: This is our variadiv va_list pointing to the string to be converted.
 * @flags: our flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 * @len: our lenth modifier.
 * @output: This is the buffer_t struct that contain a character array.
 *
 * Return: The number of bytes stored to the buffer is returned.
 */
unsigned int __ourprintf_R(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *null = "(null)";
	int i, j, size;
	unsigned int res = 0;

	(void)flags;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (__ourprintf_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	res = res + __ourprintf_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	for (i = 0; *(str + i) != '\0' && i < prec; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(str + i) == *(alpha + j))
			{
				res = res + __ourprintf_memcpy(output, (rot13 + j), 1);
				break;
			}
		}
		if (j == 52)
			res = res + __ourprintf_memcpy(output, (str + i), 1);
	}

	res = res + __ourprintf_neg_width(output, res, flags, wid);

	return (res);
}
