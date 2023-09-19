#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* Flag Modifier Macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

/* Length Modifier Macros */
#define SHORT 1
#define LONG 2

/**
 * struct buffer_s - This struct will define new a buffer struct.
 * @buffer: This will point to a character array.
 * @start: This will pointe to the start of the buffer.
 * @len: This is the length of the string stored in the buffer.
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;

/**
 * struct transform_s - This is the new type of struct converter.
 * @specifier: It is a character representing the conversion specifier.
 * @func: This is a pointer to a conversion function corresponding to specifier.
 */
typedef struct transform_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);
} transform_t;

/**
 * struct flags_s - This a new type of struct defining a flags struct.
 * @flag: This is the character representing a flag.
 * @value: The integer value to the flag.
 */
typedef struct flags_s
{
	unsigned char flag;
	unsigned char value;
} flags_t;

int _printf(const char *format, ...);

/* Conversion of our Specifier Functions */
unsigned int __ourprintf_char(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int __ourprintf_string(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int __ourprintf_decimal(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int __ourprintf_percent(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int __ourprintf_binary(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int __ourprintf_unsigned(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int __ourprintf_octal(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int __ourprintf_hexadecimal(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int __ourprintf_HEX(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int __ourprintf_STRING(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int __ourprintf_pointer(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int __ourprintf_r(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int __ourprintf_R(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);

/* Find our handlers here */
unsigned char __ourprintf_handler_flags(const char *flags, char *index);
unsigned char __ourprintf_handler_length(const char *modifier, char *index);
int __ourprintf_handler_width(va_list args, const char *modifier, char *index);
int __ourprintf_handler_precision(va_list args, const char *modifier, char *index);
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char);

/* This are our modifiers */
unsigned int __ourprintf_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);
unsigned int __ourprintf_string_width(buffer_t *output,
		unsigned char flags, int wid, int prec, int size);
unsigned int __ourprintf_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);

/* This are going to be our helper Functions */
buffer_t *init_buffer(void);
void free_buffer(buffer_t *output);
unsigned int __ourprintf_memcpy(buffer_t *output, const char *src, unsigned int n);
unsigned int __ourprintf_sbase(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec);
unsigned int __ourprintf_ubase(buffer_t *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec);

#endif /* This is the end of our MAIN_H */
