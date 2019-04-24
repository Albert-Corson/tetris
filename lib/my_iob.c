/*
** EPITECH PROJECT, 2019
** MyStdIO
** File description:
** my_iob
*/

#include "my.h"

static int _my_iob = 0;

void my_iob_init(int fd)
{
    if (!_my_iob) {
        MY_IOB.base = my_calloc(MY_BUFSIZE, sizeof(char));
        if (!MY_IOB.base)
            return;
        MY_IOB.ptr = MY_IOB.base;
        MY_IOB.cnt = MY_BUFSIZE;
        MY_IOB.fd = -1;
        _my_iob = 1;
    }
    if (fd != -1 && fd != MY_IOB.fd) {
        my_iob_flush();
        MY_IOB.fd = fd;
    }
}

void my_iob_flush(void)
{
    if (MY_IOB.fd == -1 || !MY_IOB.base)
        return;
    write(MY_IOB.fd, MY_IOB.base, MY_BUFSIZE - MY_IOB.cnt);
    my_memset(MY_IOB.base, 0, MY_BUFSIZE);
    MY_IOB.ptr = MY_IOB.base;
    MY_IOB.cnt = MY_BUFSIZE;
}

void my_iob_putc(char c)
{
    my_iob_init(-1);
    if (!MY_IOB.base)
        return;
    if (MY_IOB.cnt > 0) {
        *MY_IOB.ptr = c;
        --MY_IOB.cnt;
        ++MY_IOB.ptr;
    }
    if (c == '\n' || MY_IOB.cnt <= 0)
        my_iob_flush();
}

char my_iob_getc(void)
{
    my_iob_init(-1);
    if (!MY_IOB.base)
        return (0);
    if (!MY_IOB.base || MY_IOB.cnt < 0) {
        return (0);
    } else {
        --MY_IOB.cnt;
        ++MY_IOB.ptr;
        return (*MY_IOB.ptr);
    }
}

void my_iob_destroy(void)
{
    if (_my_iob) {
        my_iob_flush();
        if (MY_IOB.base)
            free(MY_IOB.base);
        MY_IOB.base = NULL;
        MY_IOB.ptr = NULL;
        MY_IOB.cnt = MY_BUFSIZE;
        MY_IOB.fd = -1;
        _my_iob = 0;
    }
}