/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** my_strlowcase
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str && str[i]) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        ++i;
    }
    return (str);
}