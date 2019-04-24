/*
** EPITECH PROJECT, 2019
** MyStdIO
** File description:
** my_io_vsprintf
*/

#include "my.h"

static int my_vsprintf_concat_s(char *str, va_list ap)
{
    char *arg = va_arg(ap, char *);
    char *ptr = str;
    int len = 0;

    if (!arg)
        return (0);
    while (*ptr)
        ++ptr;
    while (*arg) {
        ptr[len++] = *arg;
        ++arg;
    }
    return (len);
}

static int my_vsprintf_concat_di(char *str, va_list ap)
{
    char *arg = my_itoa(va_arg(ap, int));
    int arg_len = 0;
    int str_len = 0;

    if (!arg)
        return (0);
    arg_len = my_memlen(arg, sizeof(char));
    str_len = my_memlen(str, sizeof(char));
    my_memncpy(str + str_len, arg, arg_len);
    free(arg);
    return (arg_len);
}

static int my_vsprintf_concat_c(char *str, va_list ap)
{
    char arg = va_arg(ap, int);
    int str_len = 0;

    if (!arg)
        return (0);
    str_len = my_memlen(str, sizeof(char));
    str[str_len] = arg;
    return (1);
}

int my_vsprintf_concat_data(char *str, char spec, va_list ap)
{
    static char const *flags = "sdic";
    static int (* const concat_fns[4])(char *, va_list) = {
        my_vsprintf_concat_s,
        my_vsprintf_concat_di,
        my_vsprintf_concat_di,
        my_vsprintf_concat_c
    };
    int len = my_memlen(str, sizeof(char));
    int index = -1;
    char *flagptr = my_strchr(flags, spec);

    if (flagptr) {
        index = flagptr - flags;
        return (concat_fns[index](str, ap));
    } else {
        str[len] = '%';
        str[len + 1] = spec;
        return (2);
    }
}