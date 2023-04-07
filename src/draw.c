/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-04-06 - 15:38 +0200
 * 1st author:  evan.lebihan - evan.lebihan
 * description: draw.c
 */
#include "stu.h"

void draw(struct display *ds)
{
    fov(ds);
    //    draw_wall(ds);
    send_ray_len(ds, ds->angle, RED);
}
