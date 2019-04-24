/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** my_iob_location
*/

#include "my.h"

my_FILE *my_iob_location(void)
{
    static my_FILE my_iob;

    return (&my_iob);
}