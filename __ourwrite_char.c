#include "main.h"
/**
 * __ourwrite_char - This function will write the character c to the output
 * @c: This is the  character to be printed
 *
 * Return: On success show 1.
 * On error, give -1 is returned, and error is set accordingly.
 */
int __ourwrite_char(char c)
{
	return (write(1, &c, 1));
}
