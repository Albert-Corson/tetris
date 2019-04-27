/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** collisions
*/

#include "tetris.h"

int block_collides(tetris_t *hub, vector_t pos, vector_t oft)
{
    pattern_t *pattern = hub->map.curr_tetrimino->patterns;
    bool collide = FALSE;

    if (pattern->pattern[oft.y][oft.x] == -1)
        return (0);
    collide = (!collide ? pos.x < 0 || pos.x >= hub->map.size.x : collide);
    collide = (!collide ? pos.y < 0 || pos.y >= hub->map.size.y : collide);
    collide = (!collide ? hub->map.map[pos.y][pos.x] >= 0 : collide);
    return (collide);
}

int can_translate_tetrimino(tetris_t *hub, vector_t v)
{
    pattern_t *pattern = NULL;
    vector_t src = VECT(0, 0);
    vector_t pos = VECT(0, 0);
    vector_t oft = VECT(0, 0);
    bool collide = FALSE;

    FAIL_IF(!hub->map.curr_tetrimino || !hub->map.curr_tetrimino->patterns, 0);
    src = VECT(hub->map.tetrimino_pos.x + v.x, hub->map.tetrimino_pos.y + v.y);
    pattern = hub->map.curr_tetrimino->patterns;
    while (!collide && oft.y < pattern->size.y) {
        oft.x = 0;
        while (!collide && oft.x < pattern->size.x) {
            pos = VECT(src.x + oft.x, src.y + oft.y);
            collide = block_collides(hub, pos, oft);
            ++oft.x;
        }
        ++oft.y;
    }
    return (!collide);
}