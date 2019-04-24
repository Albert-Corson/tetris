/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** main
*/

#include "tetris.h"

tetris_t *tetris_var(int argc, char const *argv[])
{
    tetris_t *ret = malloc(sizeof(*ret));

    FAIL_IF(!ret, NULL);
}

int main(int argc, char const *argv[])
{
    tetris_t *hub = init_tetris_var(argc, argv);

    FAIL_IF(!hub, 84);
    show_usage();
    initscr();
    endwin();
    return (0);
}