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
    vector_t game = VECT(((hub->map.size.x / 2) + 25) * 2, hub->map.size.y);

    if (scr_size.x < game.x || scr_size.y < game.y) {
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
    vector_t next;

    src.x = (scr_size.x - map.x * 2) / 2;
    src.y = (scr_size.y - map.y) / 2;
    hub->map.s_elapsed = time(NULL) - hub->map.s_start;
    render_board(hub, src);
    render_tetrimino(hub, src);
    render_frame(hub, src);
    render_game_info(hub, VECT(src.x + (map.x * 2) + 2, src.y - 1));
    next = VECT(src.x + (map.x * 2) + 2, src.y - 1 + (hub->map.size.y / 2));
    render_next_tetrimino(hub, next);
}

void render_game_over(tetris_t *hub, vector_t scr_size)
{
    vector_t src = VECT(0, 0);

    src.x = (scr_size.x - 10) / 2;
    src.y = (scr_size.y) / 2;
    mvaddstr(src.y, src.x, "GAME OVER!");
    FAIL_IF_VOID(hub->high_score > hub->map.score);
    hub->high_score = hub->high_score;
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
            render_game_over(hub, scr_size);
    } else {
        hub->map.state = gs_paused;
    }
}