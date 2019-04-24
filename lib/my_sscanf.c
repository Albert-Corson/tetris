/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** my_vsscanf
*/

#include "my.h"

int my_scan(char const *format, char const **str, va_list ap);

int my_vsscanf(const char *str, const char *format, va_list ap)
{
    int status = 0;

    while (status != -1 && *format) {
        if (*format == '%' && format[1] != '\0') {
            status += my_scan(&format[1], &str, ap);
            format += 2;
        } else if (*format == *str) {
            ++format;
            ++str;
        } else
            status = -1;
    }
    return (status);
}

int my_sscanf(const char *str, const char *format, ...)
{
    int status = 0;

    va_list ap;
    va_start(ap, format);
    status = my_vsscanf(str, format, ap);
    va_end(ap);
    return (status);
}