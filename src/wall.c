/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-06 - 14:28 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: wall.c
 */

#include "stu.h"

int clear_pixelwall(struct display *ds)
{
    t_bunny_accurate_position wallpx;
    t_bunny_position tmp;

    wallpx.x = 0;
    wallpx.y = 0;
    tmp = pos_from_accurate(&wallpx);
    while (wallpx.y <= ds->ymax) {
        while (wallpx.x < ds->xmax) {
            if (get_position(ds, wallpx) == 1) {
                put_pixel(&tmp, ds->ds_px, ds->wall);
            }
            wallpx.x += 1;
        }
        wallpx.x = 0;
        wallpx.y += 1;
    }
    return (0);
}
