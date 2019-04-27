/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** list_sort
*/

#include "tetris.h"

void swap_nodes(tetris_t *hub, tetrimino_t *tile)
{
    tetrimino_t *prev = NULL;
    tetrimino_t *next = NULL;

    FAIL_IF_VOID(!hub || !tile || !tile->next);
    next = tile->next;
    while (list_poll((void *)tile, (void **)&prev)) {}
    if (tile == hub->tetriminos)
        hub->tetriminos = next;
    tile->next = next->next;
    next->next = tile;
    prev->next = next;
}

int compare_names(tetrimino_t *tmp)
{
    char *cpy1 = my_strlowcase(my_strdup(tmp->filename));
    char *cpy2 = my_strlowcase(my_strdup(tmp->next->filename));
    int check = 0;

    check = my_strcmp(cpy1, cpy2);
    if (check == 0)
        check = my_strcmp(tmp->filename, tmp->next->filename);
    free(cpy1);
    free(cpy2);
    return (check);
}

void sort_list(tetris_t *hub)
{
    tetrimino_t *tmp = hub ? hub->tetriminos : NULL;
    int is_sorted = 1;
    int check = 0;

    FAIL_IF_VOID(!hub || !hub->tetriminos)
    while ((tmp->next != hub->tetriminos || !check)) {
        if (compare_names(tmp) > 0) {
            swap_nodes(hub, tmp);
            is_sorted = 0;
        }
        tmp = tmp->next;
        check = 1;
    }
    if (is_sorted == 0)
        sort_list(hub);
}

void list_revert(tetris_t *hub)
{
    tetrimino_t *save = NULL;
    tetrimino_t *prev = NULL;
    tetrimino_t *next = NULL;
    tetrimino_t *current = NULL;
    int check = 0;

    if (!hub || !hub->tetriminos)
        return;
    while (list_poll((void *)hub->tetriminos, (void **)&prev)) {}
    save = hub->tetriminos;
    current = hub->tetriminos;
    hub->tetriminos = prev;
    while (current != save || check == 0) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        check = 1;
    }
}

void tetrimino_sort(tetris_t *hub)
{
    sort_list(hub);
}