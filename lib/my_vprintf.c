/*
** EPITECH PROJECT, 2019
** MyStdIO
** File description:
** my_vprintf
*/

#include "my.h"

static int my_vprintf_concat_s(va_list ap)
{
    char *arg = va_arg(ap, char *);
    int arg_len = 0;

    if (!arg)
        return (0);
    while (arg[arg_len])
        my_iob_putc(arg[arg_len++]);
    return (arg_len);
}

static int my_vprintf_concat_di(va_list ap)
{
    long long int arg = va_arg(ap, long long int);
    long long int size = 1;
    long long int tmp = arg;

    if (arg < 0 && (arg = -arg) && (tmp = arg))
        my_iob_putc('-');
    while (tmp >= 10) {
        tmp /= 10;
        size *= 10;
    }
    while (size >= 1) {
        my_iob_putc(arg / size + '0');
        arg -= (arg / size) * size;
        size /= 10;
    }
    return (size);
}

static int my_vprintf_concat_c(va_list ap)
{
    char arg = va_arg(ap, int);

    if (!arg)
        return (0);
    my_iob_putc(arg);
    return (1);
}

static int my_vprintf_concat_f(va_list ap)
{
    double arg = va_arg(ap, double);
    double precision = 0.01;
    double size = 1;
    double tmp = arg;

    if (arg < 0 && (arg = -arg) && (tmp = arg))
        my_iob_putc('-');
    while (tmp >= 10) {
        tmp /= 10;
        size *= 10;
    }
    while (size >= precision) {
        my_iob_putc(arg / size + '0');
        if (size >= 1 && size / 10 < 1)
            my_iob_putc('.');
        arg -= (int)(arg / size) * size;
        size /= 10;
    }
    return (size);
}

int my_vprintf_concat(char spec, va_list ap)
{
    static char const *flags = "sdicf";
    static int (* const concat_fns[5])(va_list) = {
        my_vprintf_concat_s,
        my_vprintf_concat_di,
        my_vprintf_concat_di,
        my_vprintf_concat_c,
        my_vprintf_concat_f,
    };
    int index = -1;
    char *flagptr = my_strchr(flags, spec);

    if (flagptr) {
        index = flagptr - flags;
        return (concat_fns[index](ap));
    } else {
        my_iob_putc('%');
        my_iob_putc(spec);
        return (2);
    }
}