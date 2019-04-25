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
    show_usage();
    tetriminos_show_debug(hub);
    game(hub);
    my_iob_destroy();
    return (game(hub));
}