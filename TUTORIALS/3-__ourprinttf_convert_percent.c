#include "main.h"
/**
 * __ourprintf_char - This function will change an
 * argument to an unsigned char and
 * stores it to a buffer contained in a struct.
 * @args: This is the variadic 
 * va_list pointing to the argument to be converted.
 * @flags: our flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 * @len: our length modifier.
 * @output: our buffer_t struct contain a character array.
 *
 * Return: The number of bytes stored to the buffer is returned.
 */
unsigned int __ourprintf_char(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char c;
	unsigned int res = 0;

	(void)prec;
	(void)len;

	c = va_arg(args, int);

	res = res + __ourprintf_width(output, res, flags, wid);
	res = res + __ourprintf_memcpy(output, &c, 1);
	res = res + __ourprintf_neg_width(output, res, flags, wid);

	return (res);
}
/**
 * __ourprintf_percent - This function will hold a percent sign to a
 * buffer contained in a struct.
 * @args: our variadic va_list pointing to the argument to be converted.
 * @flags: our flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 * @len: ourlength modifier.
 * @output: our buffer_t struct containing a character array is.
 *
 * Return: The number of bytes stored to the buffer (always 1).
 */
unsigned int __ourprintf_percent(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char percent = '%';
	unsigned int res = 0;

	(void)args;
	(void)prec;
	(void)len;

	res = res + __ourprintf_width(output, res, flags, wid);
	res = res + __ourprintf_memcpy(output, &percent, 1);
	res = res + __ourprintf_neg_width(output, res, flags, wid);

	return (res);
}
/**
 * __ourprintf_pointer - This function will switch
 * the address of an argument to hex and
 * stores it to a buffer contained in a struct.
 * @args: our variadic va_list pointing to the argument to be converted.
 * @flags: our flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 * @len: our length modifier.
 * @output: This is the buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer is returned.
 */
unsigned int __ourprintf_pointer(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *null = "(nil)";
	unsigned long int address;
	unsigned int res = 0;

	(void)len;

	address = va_arg(args, unsigned long int);
	if (address == '\0')
		return (__ourprintf_memcpy(output, null, 5));

	flags |= 32;
	res = res + __ourprintf_ubase(output, address, "0123456789abcdef",
			flags, wid, prec);
	res = res + __ourprintf_neg_width(output, res, flags, wid);

	return (res);
}
