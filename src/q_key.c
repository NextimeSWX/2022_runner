/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-07 - 11:30 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: Q_key.c
 */

#include "stu.h"

int q_key(struct display *ds)
{
    int i;

    i = 0;
    while (i < ds->walk && get_position(ds, ds->player) != 1) {
        ds->player = move_forward(&ds->player, ds->angle - 90, 1);
        i += 1;
    }
    if ( get_position(ds, ds->player) == 1) {
        ds->player = move_forward(&ds->player, ds->angle - 90, 1);
    }
    return (0);
}
