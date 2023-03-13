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
    t_bunny_position wallpx;

    wallpx.x = 0;
    wallpx.y = 0;
    while (wallpx.y <= ds->ymax) {
        while (wallpx.x < ds->xmax) {
            if (get_position(ds, wallpx) == 1) {
                put_pixel(&wallpx, ds->ds_px, ds->wall);
            }
            wallpx.x += 1;
        }
        wallpx.x = 0;
        wallpx.y += 1;
    }
    return (0);
}
