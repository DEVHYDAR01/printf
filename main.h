#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

int __ourwrite_char(char character);
int __ourprintf_char(va_list args, int imprint);
int __ourprintf_string(va_list args, int imprint);
int __ourprintf_integer(va_list args, int imprint);
int selector(const char *format, va_list args, int imprint);
int __ourprintf_binary(unsigned int num, int imprint);
int _printf(const char *format, ...);
int _x(unsigned int num, int imprint, int uppercase);
int __ourprintf_octal(unsigned int num, int imprint);
int __ourprintf_unsigned(unsigned int num, int imprint);
int __ourprintf_reverse(va_list args, int imprint);
int __ourprintf_pointer(va_list args, int imprint);
#endif
