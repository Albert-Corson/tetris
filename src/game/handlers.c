/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** handlers
*/

#include "tetris.h"

void key_handlers(tetris_t *hub, int key)
{
    static void (*const handlers[5])(tetris_t *, int) = {
        move_tetrimino,
        move_tetrimino,
        rotate_tetrimino,
        drop_tetrimino,
        pause_game
    };
    int keys[5] = {
        hub->controls.kleft, hub->controls.kright, hub->controls.krotate, 
        hub->controls.kdrop, hub->controls.kpause
    };
    int index = 0;

    while (index < 5) {
        if (keys[index] == key)
            handlers[index](hub, key);
        ++index;
    }
}

void move_tetrimino(tetris_t *hub, int key)
{
    if (key == hub->controls.kleft)
        translate_tetrimino(hub, VECT(-1, 0));
    else if (key == hub->controls.kright)
        translate_tetrimino(hub, VECT(1, 0));
}

void rotate_tetrimino(tetris_t *hub, int key)
{
    pattern_t *pattern = hub->map.curr_tetrimino->patterns;

    if (key != hub->controls.krotate)
        return;
    hub->map.curr_tetrimino->patterns = pattern->next;
}

void pause_game(tetris_t *hub, int key)
{
    if (key != hub->controls.kpause)
        return;
    mvaddch(5, 5, '-');
}

void drop_tetrimino(tetris_t *hub, int key)
{
    int stuck = 0;

    if (key != hub->controls.kdrop)
        return;
    while (!stuck)
        stuck = !translate_tetrimino(hub, VECT(0, 1));
}