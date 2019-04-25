/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tetris.h
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <curses.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>

#include "my.h"
#include "struct.h"

#define FAIL_IF(cond, ret) if (cond) return (ret);
#define FAIL_IF_VOID(cond) if (cond) return;
#define MIN(x, y) (x < y ? x : y)

#define VECT(x, y) (vector_t){x, y}

#define SET_COLOR(pair) if (has_colors()) attron(COLOR_PAIR(pair));
#define UNSET_COLOR(pair) if (has_colors()) attroff(COLOR_PAIR(pair));

void show_usage(void);
int list_poll(void *begin, void **buffer);
void *list_append(void **begin, void *node);
void *list_pop_next(void **node);
void table_destroy(void **table);

tetriminos_t *init_tetriminos(vector_t map_size);
tetris_t *init_tetris_var(int argc, char const *argv[]);
void destroy_tetris_var(tetris_t *var);
patern_t *patern_rotate(patern_t *patern);
void patern_destroy(patern_t *patern);
patern_t *patern_new(char **patern, vector_t size, char color);
patern_t *tetriminos_get_patern(char *filename);
void tetrimino_destroy(tetriminos_t *tile);

// DEBUG
void tetrimino_show(tetriminos_t *tile);
void tetriminos_show_debug(tetris_t *hub);
int game(tetris_t *hub);

#endif /* !TETRIS_H_ */