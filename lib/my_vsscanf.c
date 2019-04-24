/*
** EPITECH PROJECT, 2019
** MyStdIO
** File description:
** my_sscanf
*/

#include "my.h"

static int my_scan_s(char const *format, char const **str, va_list ap)
{
    char *ptr = va_arg(ap, char *);
    char delim = format[1];

    while (**str && **str != delim) {
        *ptr = **str;
        ++ptr;
        ++*str;
    }
    *ptr = 0;
    return (1);
}

static int my_scan_di(char const *format, char const **str, va_list ap)
{
    long long int *ptr = va_arg(ap, long long int *);
    long long int nbr = 0;
    int sign = 1;

    format = format;
    while (**str && (**str == '-' || **str == '+')) {
        sign = (**str == '-' ? -sign : sign);
        ++*str;
    }
    while (**str && **str >= '0' && **str <= '9') {
        nbr *= 10;
        nbr += **str - 48;
        ++*str;
    }
    *ptr = sign * nbr;
    return (1);
}

static int my_scan_f(char const *format, char const **str, va_list ap)
{
    float *ptr = va_arg(ap, float *);
    float nbr = 0;
    int sign = 1;
    float order = 1;

    format = format;
    while (**str && (**str == '-' || **str == '+')) {
        sign = (**str == '-' ? -sign : sign);
        ++*str;
    }
    while (**str && ((**str >= '0' && **str <= '9') || **str == '.')) {
        if (**str != '.' && order == 1)
            nbr *= 10;
        nbr += (**str != '.' ? (**str - 48) * order : 0);
        if (**str == '.' || order != 1)
            order /= 10;
        ++*str;
    }
    *ptr = sign * nbr;
    return (1);
}

static int my_scan_c(char const *format, char const **str, va_list ap)
{
    char *ptr = va_arg(ap, char *);

    format = format;
    *ptr = **str;
    ++*str;
    return (1);
}

int my_scan(char const *format, char const **str, va_list ap)
{
    static char const *flags = "sdicf";
    static int (* const scan_fns[5])(char const *, char const **, va_list) = {
        my_scan_s,
        my_scan_di,
        my_scan_di,
        my_scan_c,
        my_scan_f,
    };
    int index = -1;
    char *flagptr = my_strchr(flags, *format);

    if (flagptr) {
        index = flagptr - flags;
        return (scan_fns[index](format, str, ap) > 0);
    } else {
        return (0);
    }
}