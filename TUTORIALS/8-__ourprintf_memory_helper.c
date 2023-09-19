#include "main.h"
/**
 * __ourprintf_memcpy - funtion to copy n bytes from memory area src to
 * the buffer contained in a buffer_t struct.
 * @output: our buffer_t struct.
 * @src: it is a pointer to the memory area to copy.
 * @n: This is the number of bytes to be copied.
 *
 * Return: The number of bytes copied is returned.
 */
unsigned int __ourprintf_memcpy(buffer_t *output, const char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		*(output->buffer) = *(src + index);
		(output->len)++;

		if (output->len == 1024)
		{
			write(1, output->start, output->len);
			output->buffer = output->start;
			output->len = 0;
		}

		else
			(output->buffer)++;
	}

	return (n);
}

/**
 * free_buffer - function that frees a buffer_t struct.
 * @output: This is the buffer_t struct to be freed.
 */
void free_buffer(buffer_t *output)
{
	free(output->start);
	free(output);
}

/**
 * init_buffer - funtion that initializes a variable of struct type buffer_t.
 *
 * Return: it is the pointer to the initialized buffer_t.
 */
buffer_t *init_buffer(void)
{
	buffer_t *output;

	output = malloc(sizeof(buffer_t));
	if (output == NULL)
		return (NULL);

	output->buffer = malloc(sizeof(char) * 1024);
	if (output->buffer == NULL)
	{
		free(output);
		return (NULL);
	}

	output->start = output->buffer;
	output->len = 0;

	return (output);
}
