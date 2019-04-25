/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** list
*/

#include "tetris.h"

int list_poll(void *begin, void **buffer)
{
    FAIL_IF(!begin, 0);
    if (!*buffer)
        *buffer = begin;
    else if (((patern_t *)*buffer)->next != begin)
        *buffer = ((patern_t *)*buffer)->next;
    else
        return (0);
    return (1);
}

void *list_append(void **begin, void *node)
{
    patern_t *st_begin = (patern_t *)(*begin);
    patern_t *st_node = (patern_t *)node;
    patern_t *tmp = st_begin;

    FAIL_IF(!st_node, NULL);
    if (*begin == NULL) {
        *begin = node;
    } else {
        while (tmp->next != st_begin) {
            tmp = (patern_t *)tmp->next;
        }
        tmp->next = node;
        st_node->next = *begin;
    }
    return (node);
}

void *list_pop_next(void **node)
{
    patern_t *st_node = NULL;
    patern_t *ret = NULL;

    FAIL_IF(!node || !*node, NULL);
    st_node = *node;
    if (st_node->next == st_node) {
        *node = NULL;
        return (st_node);
    }
    st_node = *node;
    ret = st_node->next;
    st_node->next = ret->next;
    return (ret);
}