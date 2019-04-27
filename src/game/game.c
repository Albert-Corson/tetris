/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** game
*/

#include "tetris.h"

void initwin(void)
{
    initscr();
    flushinp();
    noecho();
    nodelay(stdscr, TRUE);
    timeout(50);
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();
    use_default_colors();
    init_pair(8, 0, 0);
    init_pair(1, 1, 1);
    init_pair(2, 2, 2);
    init_pair(3, 3, 3);
    init_pair(4, 4, 4);
    init_pair(5, 5, 5);
    init_pair(6, 6, 6);
    init_pair(7, 7, 7);
}

void run_gameplay(tetris_t *hub)
{
    if (hub->map.state != gs_running)
        return;
    if (!fall_tetrimino(hub)) {
        if (hub->map.tetrimino_pos.y <= 0)
            hub->map.state = gs_over;
        merge_tetrimino(hub);
        hub->map.speed = 500 - (10 * hub->map.level);
    }
}

int game(tetris_t *hub)
{
    gstate_t *state = &hub->map.state;
    int key = 0;

    initwin();
    pick_tetriminos(hub);
    *state = gs_running;
    while (key != hub->controls.kquit) {
        clear();
        map_rm_line(hub);
        render_state(hub);
        run_gameplay(hub);
        key_handlers(hub, key);
        refresh();
        key = getch();
    }
    endwin();
    return (0);
}