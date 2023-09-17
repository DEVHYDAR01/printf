#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
* struct transform - This struct will define a struct for signs and functions
*
* @sign: This will be the  operator
* @fun: This is the  function associated with it.
*/
typedef struct transform
{
       char *sign;
       int (*fun)(va_list);
}transform;

int _printf(const char *format, ...);
int __char_write(char c);
int __our_parser(const char *format, transform_t fun_list[], va_list arg_lists);

#endif
