#include "main.h"
/**
 * __ourprintf_sbase - This function will converts a
 * signed long to an inputted base and stores
 * the result to a buffer contained in a struct.
 * @output: This is the struct buffer_t struct containing a character array.
 * @num: This is a signed long to be converted.
 * @base: This is a pointer to a string containing the base to convert to.
 * @flags: This are our Flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 *
 * Return: This is the number of bytes stored to the buffer.
 */
unsigned int __ourprintf_sbase(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	int size;
	char digit, pad = '0';
	unsigned int res = 1;

	for (size = 0; *(base + size);)
		size++;

	if (num >= size || num <= -size)
		res = res + __ourprintf_sbase(output, num / size, base,
				flags, wid - 1, prec - 1);

	else
	{
		for (; prec > 1; prec--, wid--) /* Handle precision */
			res = res + __ourprintf_memcpy(output, &pad, 1);

		if (NEG_FLAG == 0) /* Handle width */
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				res = res + __ourprintf_memcpy(output, &pad, 1);
		}
	}

	digit = base[(num < 0 ? -1 : 1) * (num % size)];
	__ourprintf_memcpy(output, &digit, 1);

	return (res);
}

/**
 * __ourprintf_ubase - This function will convert an unsigned long to an inputted base and
 * stores the result to a buffer contained in a struct.
 * @output: This is a struct buffer_t struct containing a character array.
 * @num: our unsigned long to be converted.
 * @base: This is a pointer to a string containing the base to convert to.
 * @flags: our Flag modifiers.
 * @wid: our width modifier.
 * @prec: our precision modifier.
 *
 * Return: The number of bytes stored to the buffer is returned.
 */
unsigned int __ourprintf_ubase(buffer_t *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	unsigned int size, res = 1;
	char digit, pad = '0', *lead = "0x";

	for (size = 0; *(base + size);)
		size++;

	if (num >= size)
		res = res + __ourprintf_ubase(output, num / size, base,
				flags, wid - 1, prec - 1);

	else
	{
		if (((flags >> 5) & 1) == 1) /* Printing a ptr address */
		{
			wid -= 2;
			prec -= 2;
		}
		for (; prec > 1; prec--, wid--) /* Handle precision */
			res = res + __ourprintf_memcpy(output, &pad, 1);

		if (NEG_FLAG == 0) /* Handle width */
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				res = res + __ourprintf_memcpy(output, &pad, 1);
		}
		if (((flags >> 5) & 1) == 1) /* Print 0x for ptr address */
			res = res + __ourprintf_memcpy(output, lead, 2);
	}

	digit = base[(num % size)];
	__ourprintf_memcpy(output, &digit, 1);

	return (res);
}
