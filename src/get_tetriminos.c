/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** get_tetriminos
*/

#include "tetris.h"

static int skip_spaces(char *str, int index)
{
    while (str && (str[index] == ' ' || str[index] == '\t'))
        ++index;
    return (index);
}

static int size_n_color(char *str, vector_t *size, char *color)
{
    size->x = 0;
    size->y = 0;
    *color = -1;
    int i = 0;

    i = skip_spaces(str, i);
    for (; str[i] >= '0' && str[i] <= '9'; ++i)
        size->x = (size->x * 10) + (str[i] - 48);
    i = skip_spaces(str, i);
    for (; str[i] >= '0' && str[i] <= '9'; ++i)
        size->y = (size->y * 10) + (str[i] - 48);
    i = skip_spaces(str, i);
    if (str[i] >= '0' && str[i] <= '9')
        *color = 0;
    for (; str[i] >= '0' && str[i] <= '9'; ++i)
        *color = (*color * 10) + (str[i] - 48);
    i = skip_spaces(str, i);
    FAIL_IF(str[i] != '\n' || size->x == 0 || size->y == 0 || *color == -1, 0);
    return (1);
}

int fill_patern_line(char *buffer, char **line, vector_t size, char color)
{
    int i = 0;

    *line = my_calloc(size.x + 1, sizeof(char));
    while (buffer[i] && (buffer[i] == ' ' || buffer[i] == '*') && i < size.x) {
        (*line)[i] = (buffer[i] == ' ') ? -1 : color + 1;
        ++i;
    }
    if (!buffer[i] || buffer[i] == '\n') {
        for (; i < size.x; ++i)
            (*line)[i] = -1;
    }
    if (i == size.x) {
        for (; buffer[i] == 32 || buffer[i] == '\t'; ++i) {}
        i = (buffer[i] == '\0' || buffer[i] == '\n') ? -1 : i;
    }
    if (i != size.x && i != -1) {
        free(*line);
        *line = NULL;
    }
    return ((i != size.x && i != -1) ? 0 : 1);
}

static char **get_patern(FILE *fd, vector_t size, char color)
{
    char **ret = my_calloc(size.y + 1, sizeof(char *));
    char *buffer = NULL;
    size_t rd = 0;
    int n = 1;
    int i = 0;

    while ((n = getline(&buffer, &rd, fd)) > 0 && i < size.y) {
        if (!fill_patern_line(buffer, &ret[i], size, color)) {
            table_destroy((void **)ret);
            free(buffer);
            return (NULL);
        }
        ++i;
    }
    if (i != size.y || (my_strlen(buffer) != 0 && n > 0)) {
        table_destroy((void **)ret);
        free(buffer);
        return (NULL);
    }
    free(buffer);
    return (ret);
}

patern_t *tetriminos_get_patern(char *filename)
{
    char *path = my_format("./tetriminos/%s", filename);
    FILE *fd = fopen(path, "r");
    char *buffer = NULL;
    size_t rd = 0;
    char color = 0;
    vector_t size = VECT(0, 0);
    char **patern = NULL;

    FAIL_IF(!fd, NULL);
    if (getline(&buffer, &rd, fd) > 0 && size_n_color(buffer, &size, &color))
        patern = get_patern(fd, size, color);
    else
        return (NULL);
    free(path);
    free(buffer);
    fclose(fd);
    return (patern_new(patern, size, color));
}