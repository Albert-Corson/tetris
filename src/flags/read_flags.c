/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** read_flags
*/

#include "tetris.h"

int set_key(tetris_t *hub, char flag)
{
    controls_t *ctrl = &(hub->controls);
    int i = get_char_pos("lrtdqp", flag);
    int *keys[6] = {&ctrl->kleft, &ctrl->kright, &ctrl->krotate, &ctrl->kdrop, \
        &ctrl->kquit, &ctrl->kpause};
    char *keyname[6] = {"left", "right", "turn", "drop", "quit", "pause"};

    if (my_strlen(optarg) != 1) {
        my_dprintf(2, "tetris: --key-%s: invalid argument \"%s\"\n", \
        keyname[i], optarg);
        return (84);
    }
    *keys[i] = optarg[0];
    return (0);
}

int set_map_size(tetris_t *hub)
{
    int i = get_char_pos(optarg, ',');

    if (i == -1 || !my_nisnum(optarg, i) || !my_nisnum(optarg + i + 1, -1)) {
        my_dprintf(2, "tetris: --map-size: invalid argument \"%s\"\n", optarg);
        return (84);
    }
    hub->map.size.y = my_atoi(optarg);
    hub->map.size.x = my_atoi(optarg + i + 1);
    return (0);
}

int set_level(tetris_t *hub)
{
    if (!my_nisnum(optarg, -1)) {
        my_dprintf(2, "tetris: --level: invalid argument \"%s\"\n", optarg);
        return (84);
    }
    hub->map.level = my_atoi(optarg);
    return (0);
}

int do_flag(tetris_t *hub, char flag)
{
    if (flag == 'h')
        return (show_usage());
    if (flag == 'w')
        hub->show_next = false;
    else if (flag == 'D')
        hub->debug = true;
    else {
        if (flag == 'L')
            return (set_level(hub));
        else if (flag == 'm')
            return (set_map_size(hub));
        else
            return (set_key(hub, flag));
    }
    return (0);
}

int read_flags(int ac, char *const *av, tetris_t *hub)
{
    int n = 0;
    vector_t val = VECT(0, 0);
    const struct option opt[] = {{"help", no_argument, NULL, 'h'}, \
        {"level", required_argument, NULL, 'L'},
        {"key-left", required_argument, NULL, 'l'},
        {"key-right", required_argument, NULL, 'r'},
        {"key-turn", required_argument, NULL, 't'},
        {"key-drop", required_argument, NULL, 'd'},
        {"key-quit", required_argument, NULL, 'q'},
        {"key-pause", required_argument, NULL, 'p'},
        {"map-size", required_argument, NULL, 'm'},
        {"without-next", no_argument, NULL, 'w'},
        {"debug", no_argument, NULL, 'D'},
        {0, 0, 0, 0}};

    while ((val.x = getopt_long(ac, av, "L:l:r:t:d:q:p:wD", opt, &n)) >= 0) {
        FAIL_IF(val.x == '?', 84);
        val.y = do_flag(hub, val.x);
        FAIL_IF(val.y != 0, val.y);
    }
    return (0);
}