/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetrimino_debug
*/

#include "tetris.h"

void tetrimino_show(tetriminos_t *tile)
{
    int x = 0;
    int y = 0;
    char **patern = tile->paterns ? tile->paterns->patern : NULL;

    my_printf("Tetrimino : Name %s : ", tile->filename);
    if (!patern) {
        my_printf("Error\n");
        return;
    }
    my_printf("Size %d*%d : Color %d :\n", tile->paterns->size.x, \
        tile->paterns->size.y, tile->paterns->color);
    while (patern[y]) {
        my_printf("%c", (patern[y][x] == -1) ? ' ' : '*');
        ++x;
        if (patern[y][x] == 0){
            my_printf("\n");
            x = 0;
            ++y;
        }
    }
}

void tetriminos_show_debug(tetris_t *hub)
{
    tetriminos_t *curr = NULL;
    int nb = 0;

    while (list_poll((void *)hub->tetriminos, (void **)&curr))
        ++nb;
    curr = NULL;
    my_printf("Tetrimino : %d\n", nb);
    while (list_poll((void *)hub->tetriminos, (void **)&curr))
        tetrimino_show(curr);
}