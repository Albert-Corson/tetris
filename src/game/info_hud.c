/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** game_info_hud
*/

#include "tetris.h"

static void render_info_frame(vector_t pos, vector_t size, int color)
{
    int i = 0;

    SET_COLOR(color);
    for (i = pos.x; i < pos.x + size.x; i++) {
        mvaddch(pos.y, i, '-');
        mvaddch(pos.y + size.y, i, '-');
    }
    for (i = pos.y; i < pos.y + size.y + 1; i++) {
        mvaddch(i, pos.x, '|');
        mvaddch(i, pos.x + size.x, '|');
    }
    UNSET_COLOR(color);
}

void render_game_info(tetris_t *hub, vector_t pos)
{
    vector_t size = VECT(18, 8);
    int sec = hub->map.s_elapsed % 60;
    int min = (hub->map.s_elapsed - sec) / 60;
    char *str = NULL;

    render_info_frame(pos, size, 7);
    mvprintw(pos.y + 2 - 1, pos.x + 1, "High score %d", hub->high_score);
    mvprintw(pos.y + 3 - 1, pos.x + 1, "Score %d", hub->map.score);
    mvprintw(pos.y + 5 - 1, pos.x + 1, "Lines %d", hub->map.lines);
    mvprintw(pos.y + 6 - 1, pos.x + 1, "Level %d", hub->map.level);
    mvprintw(pos.y + 8 - 1, pos.x + 1, "Timer %02d:%02d", min, sec);
    free(str);
}