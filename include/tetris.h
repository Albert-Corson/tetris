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

#include "my.h"
#include "struct.h"

#define FAIL_IF(cond, ret) if (cond) return (ret);
#define FAIL_IF_VOID(cond) if (cond) return;

#define VECT(x, y) (vector_t){x, y}

void show_usage(void);

patern_t *init_tetriminos(int argc, char const *argv[], vector_t map_size);
tetris_t *init_tetris_var(int argc, char const *argv[]);
void destroy_tetris_var(tetris_t *var);

#endif /* !TETRIS_H_ */