/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** usage
*/

#include "../include/tetris.h"

int get_char_pos(char const *str, char goal)
{
    int n = 0;

    if (str == NULL)
        return (-1);
    while (str[n] != goal && str[n]) {
        ++n;
    }
    if (str[n] != goal)
        return (-1);
    return (n);
}

static char *my_copycat(char *dest, char *src, int lim)
{
    char *rtn;
    int n = 0;
    int tmp = 0;

    lim = lim == -1 ? get_char_pos(src, 0) : lim;
    if (dest == NULL)
        rtn = malloc(sizeof(char) * (lim + 1));
    else {
        rtn = malloc(sizeof(char) * (get_char_pos(dest, 0) + lim + 1));
        while (dest[n] != 0) {
            rtn[n] = dest[n];
            ++n;
        }
        free(dest);
    }
    while (src[tmp] != 0 && tmp < lim) {
        rtn[tmp + n] = src[tmp];
        ++tmp;
    }
    rtn[tmp + n] = 0;
    return (rtn);
}

static char *get_line(int fd)
{
    char *rtn = NULL;
    char buff = 0;
    int check = 0;

    if (fd < 0)
        return (NULL);
    check = read(fd, &buff, 1);
    while (check > 0) {
        if (buff != '\n') {
            rtn = my_copycat(rtn, &buff, 1);
            check = read(fd, &buff, 1);
        } else {
            rtn = my_copycat(rtn, "\0", 1);
            check = 0;
        }
    }
    return (rtn);
}

int show_usage(void)
{
    int fd = open(".legend", O_RDONLY);
    char *str = NULL;
    int i = 0;

    FAIL_IF(fd < 0, 84);
    str = get_line(fd);
    while (str) {
        if (i >= 2) {
            my_putstr(str);
            my_putstr("\n");
        }
        free(str);
        str = get_line(fd);
        ++i;
    }
    return (1);
}