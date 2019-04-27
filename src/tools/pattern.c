/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** pattern
*/

#include "tetris.h"

pattern_t *pattern_new(char **pattern, vector_t size, char color)
{
    pattern_t *new = NULL;

    FAIL_IF(!pattern || !*pattern, NULL);
    new = malloc(sizeof(*new));
    new->size = size;
    new->next = new;
    new->color = color;
    new->pattern = pattern;
    return (new);
}

pattern_t *pattern_rotate(pattern_t *pattern)
{
    pattern_t *new = malloc(sizeof(*new));
    int y = 0;
    int x = 0;
    char **model = pattern->pattern;

    FAIL_IF(!new, NULL);
    new->size = VECT(pattern->size.y, pattern->size.x);
    new->pattern = my_calloc((new->size.y + 1), sizeof(char *));
    FAIL_IF(!new->pattern, NULL);
    for (y = 0; y < new->size.y; ++y) {
        new->pattern[y] = my_calloc(new->size.x + 1, sizeof(char));
        for (x = 0; x < new->size.x; ++x)
            new->pattern[y][x] = model[pattern->size.y - (x + 1)][y];
    }
    new->color = pattern->color;
    return (new);
}

void pattern_destroy(pattern_t *pattern)
{
    FAIL_IF_VOID(!pattern);
    table_destroy((void **)pattern->pattern);
    free(pattern);
}