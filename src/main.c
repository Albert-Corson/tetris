/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** main
*/

#include "tetris.h"

int main(int argc, char *const *argv)
{
    tetris_t *hub = NULL;
    int rtn = init_tetris_var(argc, argv, &hub);

    FAIL_IF(!hub, 84);
    if (rtn == 0) {
        if (hub->debug)
            debug_mode(hub);
        keypad(stdscr, TRUE);
        rtn = game(hub);
    }
    my_iob_destroy();
    destroy_tetris_var(hub);
    return (rtn == 1 ? 0 : rtn);
}