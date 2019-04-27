/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** rand
*/

#include "tetris.h"

int rand_btw(int min, int max)
{
    double randnbr = (double)rand() / 10;

    randnbr = randnbr / ((double)RAND_MAX / 10 + 0.1);
    return (randnbr * (max - min + 1) + min);
}