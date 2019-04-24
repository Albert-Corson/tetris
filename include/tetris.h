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

#endif /* !TETRIS_H_ */