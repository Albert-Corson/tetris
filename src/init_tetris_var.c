/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** init_hub
*/

#include "tetris.h"

controls_t init_controls(void)
{
    controls_t ret;

    ret.kleft = KEY_LEFT;
    ret.kright = KEY_RIGHT;
    ret.krotate = KEY_UP;
    ret.kdrop = KEY_DOWN;
    ret.kquit = 'q';
    ret.kpause = ' ';
    return (ret);
}

game_t init_map(void)
{
    game_t ret;

    ret.level = 1;
    ret.map = NULL;
    ret.score = 0;
    ret.size = VECT(10, 20);
    ret.time = 0;
    return (ret);
}

int create_map(game_t *game)
{
    int x = 0;
    int y = 0;

    FAIL_IF(game->size.x <= 0 || game->size.y <= 0, 0);
    game->map = malloc(sizeof(char *) * (game->size.y + 1));
    FAIL_IF(!game->map, 0);
    while (y < game->size.y) {
        x = 0;
        game->map[y] = malloc(sizeof(char) * (game->size.x + 1));
        FAIL_IF(!game->map[y], 0);
        while (x < game->size.x) {
            game->map[y][x] = 32;
            ++x;
        }
        ++y;
    }
    game->map[y] = NULL;
    return (1);
}

tetris_t *init_tetris_var(int argc, char const *argv[])
{
    tetris_t *ret = malloc(sizeof(*ret));

    FAIL_IF(!ret, NULL);
    ret->controls = init_controls();
    ret->show_next = true;
    ret->debug = false;
    ret->high_score = 0;
    ret->map = init_map();
    // if (!read_flags(ret) || !create_map(&ret->map)) {
        // destroy_tetris_var(ret);
        // return (NULL);
    // }
    ret->tetriminos = init_tetriminos(argc, argv, ret->map.size);
    return (ret);
}

void destroy_tetris_var(tetris_t *var)
{
    var = var;
}