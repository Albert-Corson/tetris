/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** main
*/

#include "tetris.h"

int is_valid_tetrimino(tetris_t *hub)
{
    tetrimino_t *tmp = NULL;

    while (list_poll((void *)(hub->tetriminos), (void **)&tmp)) {
        if (tmp->patterns)
            return (1);
    }
    return (0);
}

int main(int argc, char *const *argv)
{
    tetris_t *hub = NULL;
    int rtn = init_tetris_var(argc, argv, &hub);

    FAIL_IF(!hub, 84);
    if (rtn == 0) {
        if (hub->debug)
            debug_mode(hub);
        if (!is_valid_tetrimino(hub)) {
            keypad(stdscr, TRUE);
            rtn = game(hub);
        }
    }
    my_iob_destroy();
    destroy_tetris_var(hub);
    return (rtn == 1 ? 0 : rtn);
}