#include <stdio.h>
#include <stdarg.h>

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    while (*format != '\0') {
        if (*format != '%') {
            putchar(*format);
        } else {
            format++; // Move past the '%'
            if (*format == 'd') {
                int num = va_arg(args, int);
                printf("%d", num); // Here, you can do your own formatting
            } else if (*format == 'f') {
                double num = va_arg(args, double);
                printf("%f", num); // Again, format as needed
            }
            // Add more cases for other format specifiers as needed
        }
        format++;
    }
    va_end(args);
}

int main() {
    my_printf("The answer is %d and the value of pi is %f.\n", 42, 3.14);
    return 0;
}

