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

int get_char_pos(char const *str, char goal);
int show_usage(void);
int list_poll(void *begin, void **buffer);
void *list_append(void **begin, void *node);
void *list_pop_next(void **node);
void table_destroy(void **table);
int my_nisnum(char const *str, int lim);

tetrimino_t *init_tetriminos(vector_t map_size);
int init_tetris_var(int argc, char *const *argv, tetris_t **hub);
void destroy_tetris_var(tetris_t *var);
pattern_t *pattern_rotate(pattern_t *pattern);
void pattern_destroy(pattern_t *pattern);
pattern_t *pattern_new(char **pattern, vector_t size, char color);
void tetrimino_destroy(tetrimino_t *tile);
pattern_t *tetrimino_get_pattern(char *filename);

// FLAGS
int read_flags(int argc, char *const *argv, tetris_t *var);
int set_key(tetris_t *hub, char flag);

// DEBUG
void debug_mode(tetris_t *hub);

int game(tetris_t *hub);

#endif /* !TETRIS_H_ */