/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-07 - 09:40 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: position.c
 */

#include "stu.h"

int get_position(struct display *ds, t_accurate_pos pos)
{
    int position;

    position = ds->width * (pos.y / ds->tile_size) + (pos.x / ds->tile_size);
    return (ds->map[position]);
}
