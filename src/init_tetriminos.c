/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** init_tetriminos
*/

#include "tetris.h"

tetriminos_t *tetriminos_new(vector_t map_size, char *filename)
{
    tetriminos_t *new = malloc(sizeof(*new));
    patern_t *tmp = NULL;
    int i = 0;

    new->filename = my_strndup(filename, my_strlen(filename) - 10);
    new->next = new;
    new->paterns = NULL;
    tmp = tetriminos_get_patern(filename);
    if (tmp && (tmp->size.x > map_size.x || tmp->size.x > map_size.y)) {
        patern_destroy(tmp);
    } else if (tmp && (tmp->size.y > map_size.x || tmp->size.y > map_size.y)) {
        patern_destroy(tmp);
    } else {
        new->paterns = tmp;
        while (tmp && i < 3) {
            tmp = patern_rotate(tmp);
            list_append((void **)&(new->paterns), (void *)tmp);
            ++i;
        }
    }
    return (new);
}

tetriminos_t *init_tetriminos(vector_t map_size)
{
    DIR *dir = opendir("./tetriminos/");
    struct dirent *dirent = NULL;
    tetriminos_t *ret = NULL;
    tetriminos_t *new = NULL;
    int len = 0;

    FAIL_IF(!dir, NULL);
    while ((dirent = readdir(dir))) {
        len = my_strlen(dirent->d_name);
        if (len > 10 && !my_strcmp(".tetrimino", dirent->d_name + (len - 10)))
            len = 1;
        else
            len = 0;
        if (dirent->d_type == DT_REG && len) {
            new = tetriminos_new(map_size, dirent->d_name);
            list_append((void **)&ret, (void *)new);
        }
    }
    closedir(dir);
    return (ret);
}