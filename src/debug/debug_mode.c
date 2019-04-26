/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** debug_mode
*/

#include "tetris.h"

void tetrimino_show(tetrimino_t *tile)
{
    int x = 0;
    int y = 0;
    char **pattern = tile->patterns ? tile->patterns->pattern : NULL;

    my_printf("Tetrimino : Name %s : ", tile->filename);
    if (!pattern) {
        my_printf("Error\n");
        return;
    }
    my_printf("Size %d*%d : Color %d :\n", tile->patterns->size.x, \
        tile->patterns->size.y, tile->patterns->color);
    while (pattern[y]) {
        my_printf("%c", (pattern[y][x] == -1) ? ' ' : '*');
        ++x;
        if (pattern[y][x] == 0){
            my_printf("\n");
            x = 0;
            ++y;
        }
    }
}

void tetriminos_show_debug(tetris_t *hub)
{
    tetrimino_t *curr = NULL;
    int nb = 0;

    while (list_poll((void *)hub->tetriminos, (void **)&curr))
        ++nb;
    curr = NULL;
    my_printf("Tetrimino : %d\n", nb);
    while (list_poll((void *)hub->tetriminos, (void **)&curr))
        tetrimino_show(curr);
}

void show_key(char *keyname, int keyval)
{
    int i = 0;
    int keys[7] = {32, 10, '\t', KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN};
    char *to_print[7] = {"(space)", "(return)", "(tab)", \
        "^EOD", "^EOC", "^EOA", "^EOB"};

    while (i < 7) {
        if (keys[i] == keyval) {
            my_printf("Key %s : %s\n", keyname, to_print[i]);
            return;
        }
        ++i;
    }
    my_printf("Key %s : %c\n", keyname, keyval);
}

void controls_show_debug(controls_t controls)
{
    show_key("Left", controls.kleft);
    show_key("Right", controls.kright);
    show_key("Turn", controls.krotate);
    show_key("Drop", controls.kdrop);
    show_key("Quit", controls.kquit);
    show_key("Pause", controls.kpause);
}

void debug_mode(tetris_t *hub)
{
    FAIL_IF_VOID(!hub);
    my_printf("*** DEBUG MODE ***\n");
    controls_show_debug(hub->controls);
    my_printf("Next : %s\n", hub->show_next ? "Yes" : "No");
    my_printf("Level : %d\n", hub->map.level);
    my_printf("Size : %d*%d\n", hub->map.size.y, hub->map.size.x);
    tetriminos_show_debug(hub);
    my_printf("Press any key to start Tetris\n");
}