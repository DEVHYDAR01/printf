#include "main.h"
/**
 * __ourprintf_hexadecimal - This function will convert an
 * unsigned int argument to hex using abcdef
 * and stores it to a buffer contained in a struct.
 * @args: This is the variadic va_list pointing to the argument to be converted.
 * @flags: our Flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 * @len: our length modifier.
 * @output: the struct buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer is returned.
 */
unsigned int __ourprintf_hexadecimal(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int res = 0;
	char *lead = "0x";

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		res = res + __ourprintf_memcpy(output, lead, 2);

	if (!(num == 0 && prec == 0))
		res = res + __ourprintf_ubase(output, num, "0123456789abcdef",
				flags, wid, prec);

	res = res + __ourprintf_neg_width(output, res, flags, wid);

	return (res);
}

/**
 * __ourprintf_HEX - This function will converts an
 * unsigned int argument to hex using ABCDEF
 * and stores it to a buffer contain in a struct.
 * @args: our variadic va_list pointing to the argument to be converted.
 * @flags: our Flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 * @len: our length modifier.
 * @output: our buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer is returned.
 */
unsigned int __ourprintf_HEX(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int res = 0;
	char *lead = "0X";

	if (len == LONG)
		num = va_arg(args, unsigned long);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		res = res + __ourprintf_memcpy(output, lead, 2);

	if (!(num == 0 && prec == 0))
		res = res + __ourprintf_ubase(output, num, "0123456789ABCDEF",
				flags, wid, prec);

	res = res + __ourprintf_neg_width(output, res, flags, wid);

	return (res);
}
