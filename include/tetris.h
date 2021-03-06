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

#define VECT(x, y) (vector_t){x, y}

#define SET_COLOR(id) if (has_colors() && id >= 0) attron(COLOR_PAIR(id));
#define UNSET_COLOR(id) if (has_colors()) attroff(COLOR_PAIR(id));

int get_char_pos(char const *str, char goal);
int show_usage(char *binname);
int list_poll(void *begin, void **buffer);
void *list_append(void **begin, void *node);
void *list_pop_next(void **node);
void table_destroy(void **table);
int my_nisnum(char const *str, int lim);
char *my_strlowcase(char *str);
int check_flag(char *const *av);

tetrimino_t *init_tetriminos(vector_t map_size);
int init_tetris_var(int argc, char *const *argv, tetris_t **hub);
void destroy_tetris_var(tetris_t *var);
pattern_t *pattern_rotate(pattern_t *pattern);
void pattern_destroy(pattern_t *pattern);
pattern_t *pattern_new(char **pattern, vector_t size, char color);
void tetrimino_destroy(tetrimino_t *tile);
pattern_t *tetrimino_get_pattern(char *filename);
void tetrimino_sort(tetris_t *hub);

// FLAGS
int read_flags(int argc, char *const *argv, tetris_t *var);
int set_key(tetris_t *hub, char flag);

// DEBUG
int debug_mode(tetris_t *hub);
void tetriminos_show_debug(tetris_t *hub);

// TOOLS
int rand_btw(int min, int max);
int create_map(game_t *game);

// GAME
int game(tetris_t *hub);
void pick_tetriminos(tetris_t *hub);
int can_translate_tetrimino(tetris_t *hub, vector_t v);
int translate_tetrimino(tetris_t *hub, vector_t v);
int fall_tetrimino(tetris_t *hub);
void merge_tetrimino(tetris_t *hub);
void map_rm_line(tetris_t *hub);

// RENDER
int render_scr_too_small(tetris_t *hub, vector_t scr_size);
void render_state(tetris_t *hub);
void render_game(tetris_t *hub, vector_t scr_size);
void render_game_over(tetris_t *hub, vector_t scr_size);
void render_pause(vector_t scr_size);
void render_frame(tetris_t *hub, vector_t src);
void render_board(tetris_t *hub, vector_t src);
void render_block(tetris_t *hub, vector_t dest, vector_t oft);
void render_tetrimino(tetris_t *hub, vector_t src);
void render_game_info(tetris_t *hub, vector_t pos);
void render_next_tetrimino(tetris_t *hub, vector_t pos);

// ACTIONS
void key_handlers(tetris_t *hub, int key);
void move_tetrimino(tetris_t *hub, int key);
void rotate_tetrimino(tetris_t *hub, int key);
void drop_tetrimino(tetris_t *hub, int key);
void pause_game(tetris_t *hub, int key);

#endif /* !TETRIS_H_ */