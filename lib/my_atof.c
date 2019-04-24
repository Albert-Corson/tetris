/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** my_atof
*/

#include "my.h"

float my_atof(char const *nptr)
{
    char *ptr = (char *)nptr;
    float nbr = 0;
    int sign = 1;
    float order = 1;

    while (*ptr && (*ptr == '-' || *ptr == '+')) {
        sign = (*ptr == '-' ? -sign : sign);
        ++ptr;
    }
    while (*ptr && ((*ptr >= '0' && *ptr <= '9') || *ptr == '.')) {
        if (*ptr != '.' && order == 1)
            nbr *= 10;
        nbr += (*ptr != '.' ? (*ptr - 48) * order : 0);
        if (*ptr == '.' || order != 1)
            order /= 10;
        ++ptr;
    }
    return (nbr * sign);
}