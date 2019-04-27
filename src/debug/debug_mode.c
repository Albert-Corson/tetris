/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** debug_mode
*/

#include "tetris.h"

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

int debug_mode(tetris_t *hub)
{
    int n = 1;
    int c = 0;

    FAIL_IF(!hub, 84);
    my_printf("*** DEBUG MODE ***\n");
    controls_show_debug(hub->controls);
    my_printf("Next : %s\n", hub->show_next ? "Yes" : "No");
    my_printf("Level : %d\n", hub->map.level);
    my_printf("Size : %d*%d\n", hub->map.size.y, hub->map.size.x);
    tetriminos_show_debug(hub);
    my_printf("Press any key to start Tetris\n");
    while (n > 0 && c != '\n')
        n = read(0, &c, 1);
    return (c == '\n' ? 0 : 1);
}