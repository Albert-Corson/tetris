/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** render
*/

#include "tetris.h"


int render_scr_too_small(tetris_t *hub, vector_t scr_size)
{
    vector_t pos = VECT(0, 0);

    if (scr_size.x < hub->map.size.x || scr_size.y < hub->map.size.y) {
        pos.x = (scr_size.x - 21) / 2;
        pos.y = (scr_size.y) / 2;
        clear();
        mvaddstr(pos.y, pos.x, "ENLARGE YOUR TERMINAL");
        return (1);
    } else {
        return (0);
    }
}

void render_frame(tetris_t *hub, vector_t src)
{
    vector_t pos = VECT(src.x - 2, src.y - 1);

    SET_COLOR(8);
    for (pos.x = src.x - 2; pos.x < src.x + hub->map.size.y + 2; pos.x++)
        mvaddch(pos.y, pos.x, '-');
    for (pos.y = src.y; pos.y < src.y + hub->map.size.y; pos.y++) {
        mvaddstr(pos.y, src.x - 2, "||");
        mvaddstr(pos.y, src.x + hub->map.size.x * 2, "||");
    }
    for (pos.x = src.x - 2; pos.x < src.x + hub->map.size.y + 2; pos.x++)
        mvaddch(pos.y, pos.x, '-');
    UNSET_COLOR(8);
}

void render_board(tetris_t *hub, vector_t src)
{
    vector_t oft = VECT(0, 0);

    while (oft.y < hub->map.size.y) {
        oft.x = 0;
        while (oft.x < hub->map.size.x * 2) {
            SET_COLOR(hub->map.map[oft.y][oft.x / 2]);
            mvaddch(src.y + oft.y, src.x + oft.x, ' ');
            mvaddch(src.y + oft.y, src.x + oft.x + 1, ' ');
            UNSET_COLOR(hub->map.map[oft.y][oft.x / 2]);
            oft.x += 2;
        }
        ++oft.y;
    }
}

void render_block(tetris_t *hub, vector_t dest, vector_t oft)
{
    tetrimino_t *curr = hub->map.curr_tetrimino;

    if (curr->patterns->pattern[oft.y][oft.x] != -1) {
        SET_COLOR(curr->patterns->color);
        mvaddch(dest.y + oft.y, dest.x + oft.x * 2, ' ');
        mvaddch(dest.y + oft.y, dest.x + oft.x * 2 + 1, ' ');
        UNSET_COLOR(curr->patterns->color);
    }
}

void render_tetrimino(tetris_t *hub, vector_t src)
{
    tetrimino_t *curr = hub->map.curr_tetrimino;
    vector_t dest = VECT(0, 0);
    vector_t oft = VECT(0, 0);

    FAIL_IF_VOID(!curr || !curr->patterns);
    dest.x = src.x + hub->map.tetrimino_pos.x * 2;
    dest.y = src.y + hub->map.tetrimino_pos.y;
    while (oft.y < curr->patterns->size.y) {
        oft.x = 0;
        while (oft.x < curr->patterns->size.x) {
            render_block(hub, dest, oft);
            ++oft.x;
        }
        ++oft.y;
    }
}