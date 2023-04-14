/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-06 - 14:28 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: wall.c
 */

#include "stu.h"

int draw_wall(struct display *ds)
{
    t_bunny_position drawpx;
    t_bunny_position wallpx;

    wallpx.x = 0;
    wallpx.y = 0;
    while (wallpx.y < ds->ymax) {
        while (wallpx.x < ds->xmax) {
            if (get_position(ds, wallpx) == 1)
                put_pixel(&drawpx, ds->ds_px, ds->wall);
            else if (get_position(ds, wallpx) == 0)
                put_pixel(&drawpx, ds->ds_px, ds->floor);
            wallpx.x += 8;
            drawpx.x += 2;
        }
        wallpx.x = 0;
        drawpx.x = 0;
        wallpx.y += 8;
        drawpx.y += 2;
    }
    return (0);
}


