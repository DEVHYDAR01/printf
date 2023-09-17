#include "main.h"

/**
 * __our_parser - This will hold the main string with the necessary
 * parameters also to print a formatted string.
 * @format: This is the string containing all the desired characters.
 * @fun_list: This ia a list of all of the posible functions.
 * @arg_lists: This is a list also containing all of
 * the argumentents passed to the program.
 * Return: A total count of the characters printed.
 */
int __our_parser(const char *format, transform_t fun_list[], va_list arg_lists)
{
	int k, l, int correct_value, print_chars;

	print_chars = 0;
	while (format[k] != '\0')/* looping through the main string*/
	{
		if (format[k] == '%') /*Checking for the format specifiers*/
		{
			/*looping through struct to find the right function*/
			for (l = 0; fun_list[l].sign != NULL; l++)
			{
				if (format[k + 1] == fun_list[l].sign[0])
				{
					correct_value = fun_list[l].f(arg_lists);
					if (correct_value == -1)
						return (-1);
					print_chars =  print_chars +  correct_value;
					break;
				}
			}
			if (fun_list[l].sign == NULL && format[k + 1] != ' ')
			{
				if (format[k + 1] != '\0')
				{
					_char_write(format[k]);
					_char_write(format[k + 1]);
					print_chars = print_chars + 2;
				}
				else
					return (-1);
			}
			k = k + 1; /*Updating k to skip the format sign*/
		}
		else
		{
			__char_write(format[k]); /*call of the write function*/
			print_chars++;
		}
		k++;
	}
	return (print_chars);
}
}
