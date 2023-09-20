#include "main.h"
/**
 * __ourprintf_decimal - This function will switch
 * an argument to a signed int and
 * stores it to a buffer contained in a struct.
 * @args: our va_list pointing to the argument to be converted.
 * @flags: our flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 * @len: our length modifier.
 * @output: this is buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int __ourprintf_decimal(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	long int d, copy;
	unsigned int res = 0, count = 0;
	char pad, space = ' ', neg = '-', plus = '+';

	if (len == LONG)
		d = va_arg(args, long int);
	else
		d = va_arg(args, int);
	if (len == SHORT)
		d = (short)d;

	/* Handle space flag */
	if (SPACE_FLAG == 1 && d >= 0)
		res = res + __ourprintf_memcpy(output, &space, 1);
	if (prec <= 0 && NEG_FLAG == 0) /* Handle width  */
	{
		if (d == LONG_MIN)
			count = count + 19;
		else
		{
			for (copy = (d < 0) ? -d : d; copy > 0; copy /= 10)
				count++;
		}
		count = count + (d == 0) ? 1 : 0;
		count = count + (d < 0) ? 1 : 0;
		count = count + (PLUS_FLAG == 1 && d >= 0) ? 1 : 0;
		count = count + (SPACE_FLAG == 1 && d >= 0) ? 1 : 0;
		/*  our handler plus flag when zero flag is active */
		if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && d >= 0)
			res = res + __ourprintf_memcpy(output, &plus, 1);
		/* our print negative sign when zero flag is active */
		if (ZERO_FLAG == 1 && d < 0)
			res = res + __ourprintf_memcpy(output, &neg, 1);
		pad = (ZERO_FLAG == 1) ? '0' : ' ';
		for (wid -= count; wid > 0; wid--)
			res = res + __ourprintf_memcpy(output, &pad, 1);
	}
	/* Print negative sign if zero flag is not active */
	if (ZERO_FLAG == 0 && d < 0)
		res = res + __ourprintf_memcpy(output, &neg, 1);
	/* Handle plus flag if zero flag is not active */
	if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && d >= 0))
		res = res + __ourprintf_memcpy(output, &plus, 1);
	if (!(d == 0 && prec == 0))
		res = res + __ourprintf_sbase(output, d, "0123456789",
				flags, 0, prec);
	res = res + __ourprintf_neg_width(output, res, flags, wid);
	return (res);
}
/**
 * __ourprintf_binary - This function will convert
 * an unsigned int argument to binary
 * and stores it to a buffer contained in a struct.
 * @args: our va_list pointing to the argument to be converted.
 * @flags: our flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 * @len: our length modifier.
 * @output: our buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer is returned.
 */
unsigned int __ourprintf_binary(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)len;

	return (__ourprintf_ubase(output, num, "01", flags, wid, prec));
}
/**
 * __ourprintf_octal - This function will converts
 * an unsigned int to octal and
 * stores it to a buffer contained in a struct.
 * @args: our va_list poinitng to the argument to be converted.
 * @flags: our flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 * @len: our length modifier.
 * @output: this is buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer is returned.
 */
unsigned int __ourprintf_octal(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int res = 0;
	char zero = '0';

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		res = res + __ourprintf_memcpy(output, &zero, 1);

	if (!(num == 0 && prec == 0))
		res = res + __ourprintf_ubase(output, num, "01234567",
				flags, wid, prec);

	res = res + __ourprintf_neg_width(output, res, flags, wid);

	return (res);
}
/**
 * __ourprintf_unsigned - funtion to converts an unsigned int
 * argument to decimal and stores it to a buffer contained in a struct.
 * @args: A variadic va_list pointing to the argument to be converted.
 * @flags: our Flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 * @len: our length modifier.
 * @output: our buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer is returned.
 */
unsigned int __ourprintf_unsigned(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int res = 0;

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (!(num == 0 && prec == 0))
		res = res + __ourprintf_ubase(output, num, "0123456789",
				flags, wid, prec);

	res = res + __ourprintf_neg_width(output, res, flags, wid);

	return (res);
}
