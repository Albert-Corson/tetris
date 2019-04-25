/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

#include "tetris.h"

typedef struct vector_s     vector_t;
typedef struct tetris_s     tetris_t;
typedef struct controls_s   controls_t;
typedef struct game_s       game_t;
typedef struct patern_s     patern_t;
typedef struct tetriminos_s tetriminos_t;

struct vector_s {
    int x;
    int y;
};

struct controls_s {
    int kleft;
    int kright;
    int krotate;
    int kdrop;
    int kquit;
    int kpause;
};

struct game_s {
    vector_t size;
    int score;
    int level;
    time_t start;
    char **map;
};

struct patern_s {
    patern_t *next;
    char **patern;
    vector_t size;
    char color;
};

struct tetriminos_s {
    tetriminos_t *next;
    char *filename;
    patern_t *paterns;
};

struct tetris_s {
    controls_t controls;
    game_t map;
    tetriminos_t *tetriminos;
    bool show_next;
    bool debug;
    int high_score;
};

#endif /* !STRUCT_H_ */