/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-07 - 10:08 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: Z_key.c
 */

#include "stu.h"

void z_key(struct display *ds)
{
    double rad;

    rad = deg_to_rads(ds->angle);
    while (get_position(ds, ds->player) != 1) {
        ds->player = move_forward(&ds->player, rad, ds->walk);
    }
    while (get_position(ds, ds->player) == 1) {
        ds->player = move_forward(&ds->player, (rad - M_PI), 1);
    }
}

