/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tetriminos
*/

#include "tetris.h"

tetrimino_t *get_rand_tetrimino(tetris_t *hub)
{
    tetrimino_t *tmp = NULL;
    int count = 0;
    int index = 0;

    while (list_poll(hub->tetriminos, (void **)&tmp))
        ++count;
    index = rand_btw(0, count);
    tmp = NULL;
    while (list_poll(hub->tetriminos, (void **)&tmp) && index > 0)
        --index;
    if (!tmp || !tmp->patterns)
        return (get_rand_tetrimino(hub));
    else
        return (tmp);
}

void pick_tetriminos(tetris_t *hub)
{
    hub->map.curr_tetrimino = hub->map.next_tetrimino;
    if (!hub->map.curr_tetrimino)
        hub->map.curr_tetrimino = get_rand_tetrimino(hub);
    hub->map.next_tetrimino = get_rand_tetrimino(hub);
}

int translate_tetrimino(tetris_t *hub, vector_t v)
{
    bool collide = !can_translate_tetrimino(hub, v);

    if (!collide) {
        hub->map.tetrimino_pos.x += v.x;
        hub->map.tetrimino_pos.y += v.y;
    }
    return (!collide);
}

void merge_tetrimino(tetris_t *hub)
{
    int max_x = hub->map.size.x;
    pattern_t *pattern = hub->map.curr_tetrimino->patterns;
    vector_t pos = hub->map.tetrimino_pos;
    vector_t oft = VECT(0, 0);
    char pat_ch = 0;
    char map_ch = 0;

    for (oft.y = 0; oft.y < pattern->size.y; oft.y++) {
        for (oft.x = 0; oft.x < pattern->size.x; oft.x++) {
            map_ch = hub->map.map[pos.y + oft.y][pos.x + oft.x];
            pat_ch = pattern->pattern[oft.y][oft.x];
            map_ch = (map_ch == -1 && pat_ch > 0 ? pattern->color : map_ch);
            hub->map.map[pos.y + oft.y][pos.x + oft.x] = map_ch;
        }
    }
    if (hub->map.state == gs_running) {
        pick_tetriminos(hub);
        max_x -= hub->map.curr_tetrimino->patterns->size.x;
        hub->map.tetrimino_pos = VECT(rand_btw(0, max_x), 0);
    }
}

int fall_tetrimino(tetris_t *hub)
{
    int moves = 1;
    clock_t *last_clock = &hub->map.ms_last_clock;
    clock_t *elapsed = &hub->map.ms_elapsed;

    *elapsed += ((clock() - *last_clock) * 100) / (CLOCKS_PER_SEC / 1000);
    *last_clock = clock();
    moves = (*elapsed >= hub->map.speed ? 0 : 1);
    while (*elapsed >= hub->map.speed) {
        *elapsed -= hub->map.speed;
        moves += translate_tetrimino(hub, VECT(0, 1));
    }
    return (moves > 0);
}