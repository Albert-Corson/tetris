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
    noecho();
    nodelay(stdscr, TRUE);
    timeout(100);
    curs_set(0);
    keypad(stdscr, TRUE);
    initcolors();
}

int render_scr_too_small(game_t *game, vector_t scr_size)
{
    vector_t pos = VECT(0, 0);

    if (scr_size.x < game->size.x || scr_size.y < game->size.y) {
        pos.x = (scr_size.x - 21) / 2;
        pos.y = (scr_size.y) / 2;
        clear();
        mvaddstr(pos.y, pos.x, "ENLARGE YOUR TERMINAL");
        return (1);
    } else {
        return (0);
    }
}

void render_frame(game_t *game, vector_t src)
{
    vector_t pos = VECT(src.x - 1, src.y - 1);

    SET_COLOR(8);
    for (pos.x = src.x - 2; pos.x < src.x + game->size.y + 2; pos.x++)
        mvaddch(pos.y, pos.x, '-');
    for (pos.y = src.y; pos.y < src.y + game->size.y; pos.y++) {
        mvaddch(pos.y, src.x - 2, "||");
        mvaddstr(pos.y, src.x + game->size.x * 2, "||");
    }
    for (pos.x = src.x - 2; pos.x < src.x + game->size.y + 2; pos.x++)
        mvaddch(pos.y, pos.x, '-');
    UNSET_COLOR(8);
}

void render(game_t *game)
{
    vector_t src = VECT(0, 0);
    vector_t oft = VECT(0, 0);
    vector_t scr_size = VECT(0, 0);

    getmaxyx(stdscr, scr_size.y, scr_size.x);
    if (render_scr_too_small(game, scr_size))
        return;
    src.x = (scr_size.x - game->size.x * 2) / 2;
    src.y = (scr_size.y - game->size.y) / 2;
    render_frame(game, src);
    while (oft.y < game->size.y) {
        oft.x = 0;
        while (oft.x < game->size.x * 2) {
            SET_COLOR(game->map[oft.y][oft.x / 2]);
            mvaddch(src.y + oft.y, src.x + oft.x, ' ');
            mvaddch(src.y + oft.y, src.x + oft.x + 1, ' ');
            UNSET_COLOR(game->map[oft.y][oft.x / 2]);
            oft.x += 2;
        }
        ++oft.y;
    }
}

int game(tetris_t *hub)
{
    int running = 1;
    int key = 0;

    initwin();
    while (running) {
        clear();
        render(&hub->map);
        mvprintw(1, 1, "%ld", time(NULL) - hub->map.start);
        mvprintw(0, 0, "%d", key);
        refresh();
        key = getch();
    }
    endwin();
    return (0);
}