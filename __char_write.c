#include "main.h"

/**
 * _write_char - This  writes the character c to stdout
 * @c: This is the  character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int __char_write(char c)
{
	return (write(1, &c, 1));
}
