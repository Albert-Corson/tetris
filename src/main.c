/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** main
*/

#include "tetris.h"

int main(int argc, char const *argv[])
{
    tetris_t *hub = init_tetris_var(argc, argv);

    FAIL_IF(!hub, 84);
    keypad(stdscr, TRUE);
    // show_usage();
    // initscr();
    // endwin();
    tetriminos_show_debug(hub);
    my_iob_destroy();
    return (0);
}