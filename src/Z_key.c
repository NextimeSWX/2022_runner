/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-07 - 10:08 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: Z_key.c
 */

#include "stu.h"

int Z_key(struct display *ds)
{
    int i;

    i = 0;
    while (i <= ds->walk && get_position(ds, ds->player) != 1) {
        ds->player.y -= 1;
        i += 1;
    }
    if (get_position(ds, ds->player) == 1) {
        ds->player.y += 1;
    }
    return (0);
}

