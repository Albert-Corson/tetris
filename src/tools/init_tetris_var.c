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
    ret.start = time(NULL);
    return (ret);
}

int create_map(game_t *game)
{
    vector_t pos = VECT(0, 0);

    FAIL_IF(game->size.x <= 0 || game->size.y <= 0, 0);
    game->map = my_calloc(game->size.y + 1, sizeof(char *));
    FAIL_IF(!game->map, 0);
    while (pos.y < game->size.y) {
        game->map[pos.y] = malloc(sizeof(char) * (game->size.x + 1));
        my_memset(game->map[pos.y], 1, game->size.x);
        game->map[pos.y][game->size.x] = 0;
        FAIL_IF(!game->map[pos.y], 0);
        ++pos.y;
    }
    return (1);
}

int init_tetris_var(int argc, char *const *argv, tetris_t **hub)
{
    tetris_t *ret = NULL;
    int check = -1;

    *hub = malloc(sizeof(*ret));
    ret = *hub;
    FAIL_IF(!ret, 84);
    ret->controls = init_controls();
    ret->show_next = true;
    ret->debug = false;
    ret->high_score = 0;
    ret->map = init_map();
    ret->tetriminos = NULL;
    check = read_flags(argc, argv, ret);
    if (check == 84 || !create_map(&ret->map)) {
        destroy_tetris_var(ret);
        *hub = NULL;
    } else if (check == 0)
        ret->tetriminos = init_tetriminos(ret->map.size);
    return (check);
}

void destroy_tetris_var(tetris_t *var)
{
    table_destroy((void **)var->map.map);
    while (var->tetriminos)
        tetrimino_destroy(list_pop_next((void **)&(var->tetriminos)));
    tetrimino_destroy(var->tetriminos);
    free(var);
}