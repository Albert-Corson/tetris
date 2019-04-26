/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** init_tetriminos
*/

#include "tetris.h"

tetrimino_t *tetrimino_new(vector_t map_size, char *filename)
{
    tetrimino_t *new = malloc(sizeof(*new));
    pattern_t *tmp = NULL;
    int i = 0;

    new->filename = my_strndup(filename, my_strlen(filename) - 10);
    new->next = new;
    new->patterns = NULL;
    tmp = tetrimino_get_pattern(filename);
    if (tmp && (tmp->size.x > map_size.x || tmp->size.x > map_size.y)) {
        pattern_destroy(tmp);
    } else if (tmp && (tmp->size.y > map_size.x || tmp->size.y > map_size.y)) {
        pattern_destroy(tmp);
    } else {
        new->patterns = tmp;
        while (tmp && i < 3) {
            tmp = pattern_rotate(tmp);
            list_append((void **)&(new->patterns), (void *)tmp);
            ++i;
        }
    }
    return (new);
}

tetrimino_t *init_tetriminos(vector_t map_size)
{
    DIR *dir = opendir("./tetriminos/");
    struct dirent *dirent = NULL;
    tetrimino_t *ret = NULL;
    tetrimino_t *new = NULL;
    int len = 0;

    FAIL_IF(!dir, NULL);
    while ((dirent = readdir(dir))) {
        len = my_strlen(dirent->d_name);
        if (len > 10 && !my_strcmp(".tetrimino", dirent->d_name + (len - 10)))
            len = 1;
        else
            len = 0;
        if (dirent->d_type == DT_REG && len) {
            new = tetrimino_new(map_size, dirent->d_name);
            list_append((void **)&ret, (void *)new);
        }
    }
    closedir(dir);
    return (ret);
}

void tetrimino_destroy(tetrimino_t *tile)
{
    FAIL_IF_VOID(!tile);
    free(tile->filename);
    while (tile->patterns)
        pattern_destroy(list_pop_next((void **)&(tile->patterns)));
    free(tile);
}