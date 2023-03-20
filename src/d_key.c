/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-07 - 11:32 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: D_key.c
 */

#include "stu.h"

int d_key(struct display *ds)
{
    int i;

    i = 0;
    while (i < ds->walk && get_position(ds, ds->player) != 1) {
        ds->player = move_forward(&ds->player, ds->angle + 90, 1);
        i += 1;
    }
    if ( get_position(ds, ds->player) == 1) {
        ds->player = move_forward(&ds->player, ds->angle + 90, 1);
    }
    return (0);
}
