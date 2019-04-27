/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** map_rm_line
*/

#include "tetris.h"

static void rm_line(char **map, int line)
{
    int x = 0;

    my_memset(map[line], -1, my_strlen(map[line]));
    while (line > 1) {
        x = 0;
        while (map[line - 1][x]) {
            map[line][x] = map[line - 1][x];
            ++x;
        }
        --line;
    }
}

void map_rm_line(tetris_t *hub)
{
    int nb_removed = 0;
    int y = 0;

    while (hub->map.map[y]) {
        if (get_char_pos(hub->map.map[y], -1) == -1) {
            rm_line(hub->map.map, y);
            ++nb_removed;
        }
        ++y;
    }
    hub->map.lines += nb_removed;
    hub->map.level = (hub->map.lines - hub->map.lines % 10) / 10;
}