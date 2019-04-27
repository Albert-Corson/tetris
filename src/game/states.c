/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** states
*/

#include "tetris.h"

int render_scr_too_small(tetris_t *hub, vector_t scr_size)
{
    vector_t pos = VECT(0, 0);

    if (scr_size.x < hub->map.size.x || scr_size.y < hub->map.size.y) {
        clear();
        pos.x = (scr_size.x - 21) / 2;
        pos.y = (scr_size.y) / 2;
        mvaddstr(pos.y, pos.x, "ENLARGE YOUR TERMINAL");
        return (1);
    } else {
        return (0);
    }
}

void render_game(tetris_t *hub, vector_t scr_size)
{
    vector_t src = VECT(0, 0);
    vector_t map = hub->map.size;

    src.x = (scr_size.x - map.x * 2) / 2;
    src.y = (scr_size.y - map.y) / 2;
    hub->map.s_elapsed = time(NULL) - hub->map.s_start;
    render_board(hub, src);
    render_tetrimino(hub, src);
    render_frame(hub, src);
    render_game_info(hub, VECT(src.x + (map.x * 2) + 2, src.y - 1));
}

void render_game_over(vector_t scr_size)
{
    vector_t src = VECT(0, 0);

    src.x = (scr_size.x - 10) / 2;
    src.y = (scr_size.y) / 2;
    mvaddstr(src.y, src.x, "GAME OVER!");
}

void render_pause(vector_t scr_size)
{
    vector_t src = VECT(0, 0);
    src.x = (scr_size.x - 5) / 2;
    src.y = (scr_size.y) / 2;
    mvaddstr(src.y, src.x, "PAUSE");
}

void render_state(tetris_t *hub)
{
    vector_t scr_size = VECT(0, 0);

    getmaxyx(stdscr, scr_size.y, scr_size.x);
    if (!render_scr_too_small(hub, scr_size)) {
        render_game(hub, scr_size);
        if (hub->map.state == gs_paused) {
            render_pause(scr_size);
            hub->map.ms_last_clock = clock();
        } else if (hub->map.state == gs_over)
            render_game_over(scr_size);
    } else {
        hub->map.state = gs_paused;
    }
}