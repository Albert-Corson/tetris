/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** check_flag
*/

#include "tetris.h"

int check_flag(char *const *av)
{
    int i = 0;
    int len = 0;
    char *flags[20] = {"--help", "-L", "--level", "-l", "--key-left", "-r", \
    "--key-right", "-t", "--key-turn", "-d", "--key-drop", "-q", "--key-quit", \
    "-p", "--key-pause", "--map-size", "-w", "--without-next", "-D", "--debug"};

    FAIL_IF(!av[optind], 1);
    while (i < 20) {
        len = my_strlen(flags[i]);
        if (!my_strncmp(av[optind], flags[i], len))
            return (1);
        ++i;
    }
    my_dprintf(2, "%s: unrecognized option '%s'\n", av[0], av[optind]);
    return (0);
}