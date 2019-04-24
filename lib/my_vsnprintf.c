/*
** EPITECH PROJECT, 2019
** MyStdIO
** File description:
** my_io_vsnprintf
*/

#include "my.h"

static int my_vsnprintf_concat_s(char *str, size_t size, va_list ap)
{
    char *arg = va_arg(ap, char *);
    char *ptr = str;
    int len = 0;

    if (!arg)
        return (0);
    while (*ptr)
        ++ptr;
    while (*arg && (size_t)len < size) {
        ptr[len++] = *arg;
        ++arg;
    }
    return (len);
}

static int my_vsnprintf_concat_di(char *str, size_t size, va_list ap)
{
    char *arg = my_itoa(va_arg(ap, int));
    int arg_len = 0;
    int str_len = 0;

    size = size;
    if (!arg)
        return (0);
    arg_len = my_strlen(arg);
    str_len = my_strlen(str);
    my_memncpy(str + str_len, arg, arg_len);
    free(arg);
    return (arg_len);
}

static int my_vsnprintf_concat_c(char *str, size_t size, va_list ap)
{
    char arg = va_arg(ap, int);
    int str_len = 0;

    if (!arg)
        return (0);
    str_len = my_strlen(str);
    if (size > 0)
        str[str_len] = arg;
    return (size > 0);
}

int my_vsnprintf_concat_data(char *str, size_t size, char spec, va_list ap)
{
    static char const *flags = "sdic";
    static int (* const concat_fns[4])(char *, size_t, va_list) = {
        my_vsnprintf_concat_s,
        my_vsnprintf_concat_di,
        my_vsnprintf_concat_di,
        my_vsnprintf_concat_c
    };
    int index = -1;
    int len = my_strlen(str);
    char *flagptr = my_strchr(flags, spec);

    if (flagptr) {
        index = flagptr - flags;
        return (concat_fns[index](str, size, ap));
    } else {
        if ((size_t)(len) <= size)
            str[len] = '%';
        if ((size_t)(len + 1) <= size)
            str[len + 1] = spec;
        return (2);
    }
}