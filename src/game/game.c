/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** game
*/

#include "tetris.h"

void initcolors(void)
{
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

void initwin(void)
{
    initscr();
    flushinp();
    noecho();
    nodelay(stdscr, TRUE);
    timeout(50);
    curs_set(0);
    keypad(stdscr, TRUE);
    initcolors();
}

void render(tetris_t *hub, bool running)
{
    vector_t src = VECT(0, 0);
    vector_t scr_size = VECT(0, 0);

    getmaxyx(stdscr, scr_size.y, scr_size.x);
    src.x = (scr_size.x - hub->map.size.x * 2) / 2;
    src.y = (scr_size.y - hub->map.size.y) / 2;
    if (render_scr_too_small(hub, scr_size))
        return;
    render_board(hub, src);
    render_tetrimino(hub, src);
    render_frame(hub, src);
    if (!running) {
        src.x = (scr_size.x - 10) / 2;
        src.y = (scr_size.y) / 2;
        mvaddstr(src.y, src.x, "GAME OVER!");
    }
}

int game(tetris_t *hub)
{
    int running = 1;
    int key = 0;
    int speed = 500;

    initwin();
    pick_tetriminos(hub);
    while (key != hub->controls.kquit) {
        clear();
        if (running && !fall_tetrimino(hub, speed)) {
            running = (hub->map.tetrimino_pos.y > 0);
            merge_tetrimino(hub, running);
            speed -= 1;
        }
        map_rm_line(hub);
        render(hub, running);
        if (running)
            key_handlers(hub, key);
        refresh();
        key = getch();
    }
    endwin();
    return (0);
}