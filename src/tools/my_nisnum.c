/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** my_isnum
*/

int my_nisnum(char const *str, int lim)
{
    int i = 0;

    while (str[i] && (i < lim || lim == -1)) {
        if (str[i] < 48 || str[i] >  57)
            return (0);
        ++i;
    }
    return (1);
}