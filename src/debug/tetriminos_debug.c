/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tetriminos_debug
*/

#include "tetris.h"

int is_more_to_print(char *str)
{
    int i = 0;

    while (str && str[i] == -1)
        ++i;
    if (str[i] == 0)
        return (0);
    return (1);
}

void tetrimino_show(tetrimino_t *tile)
{
    int x = 0;
    int y = 0;
    char **pattern = tile->patterns ? tile->patterns->pattern : NULL;

    my_printf("Tetrimino : Name %s : ", tile->filename);
    if (!pattern) {
        my_printf("Error\n");
        return;
    }
    my_printf("Size %d*%d : Color %d :\n", tile->patterns->size.x, \
    tile->patterns->size.y, tile->patterns->color);
    while (pattern[y]) {
        my_printf("%c", (pattern[y][x] == -1) ? ' ' : '*');
        ++x;
        if (pattern[y][x] == 0 || !is_more_to_print(pattern[y] + x)){
            my_printf("\n");
            x = 0;
            ++y;
        }
    }
}

void tetriminos_show_debug(tetris_t *hub)
{
    tetrimino_t *curr = NULL;
    int nb = 0;

    while (list_poll((void *)hub->tetriminos, (void **)&curr))
        ++nb;
    curr = NULL;
    my_printf("Tetrimino : %d\n", nb);
    while (list_poll((void *)hub->tetriminos, (void **)&curr))
        tetrimino_show(curr);
}