/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-04-27 - 08:55 +0200
 * 1st author:  evan.lebihan - evan.lebihan
 * description: draw.c
 */

#include "stu.h"

void draw(struct display *ds, unsigned int color)
{
    fov(ds);
    draw_wall(ds);
    send_ray_len(ds, ds->angle, color);
}
