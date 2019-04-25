/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** patern
*/

#include "tetris.h"

patern_t *patern_new(char **patern, vector_t size, char color)
{
    patern_t *new = NULL;

    FAIL_IF(!patern || !*patern, NULL);
    new = malloc(sizeof(*new));
    new->size = size;
    new->next = new;
    new->color = color;
    new->patern = patern;
    return (new);
}

patern_t *patern_rotate(patern_t *patern)
{
    patern_t *new = malloc(sizeof(*new));
    int y = 0;
    int x = 0;
    char **model = patern->patern;

    FAIL_IF(!new, NULL);
    new->size = VECT(patern->size.y, patern->size.x);
    new->patern = my_calloc((new->size.y + 1), sizeof(char *));
    FAIL_IF(!new->patern, NULL);
    for (y = 0; y < new->size.y; ++y) {
        new->patern[y] = my_calloc(new->size.x + 1, sizeof(char));
        for (x = 0; x < new->size.x; ++x)
            new->patern[y][x] = model[patern->size.y - (x + 1)][y];
    }
    return (new);
}

void patern_destroy(patern_t *patern)
{
    FAIL_IF_VOID(!patern);
    table_destroy((void **)patern->patern);
    free(patern);
}