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
    srand(time(0));
    if (rtn == 0) {
        if (hub->debug)
            rtn = debug_mode(hub);
        if (rtn == 0 && is_valid_tetrimino(hub))
            rtn = game(hub);
        else if (rtn != 0)
            rtn = 84;
    }
    my_iob_destroy();
    destroy_tetris_var(hub);
    return (rtn == 1 ? 0 : rtn);
}