/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-07 - 10:29 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: S_key.c
 */

#include "stu.h"

int S_key(void *data)
{
    struct display *ds;
    int i;
    int tmp;

    ds = data;
    tmp = ds->y;
    i = 0;
    while (i < ds->walk && get_position(&ds) != 1) {
        ds->player.y += 1;
        i += 1;
    }
    if ( get_position(&ds) == 1) {
        ds->player.y -= 1;
    }
    return (0);
}

