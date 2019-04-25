/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** table
*/

#include "tetris.h"

void table_destroy(void **table)
{
    char **st_table = (char **)table;
    int i = 0;

    while (table && st_table[i]) {
        free(st_table[i]);
        ++i;
    }
    free(table);
}