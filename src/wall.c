/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-06 - 14:28 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: wall.c
 */

#include "stu.h"

static void blit_at_origin(struct display *ds)
{
    t_bunny_position pos;

    pos.x = 0;
    pos.y = 0;
    bunny_blit(&ds->ds_win->buffer, &ds->ds_px->clipable, &pos);
    bunny_display(ds->ds_win);
}

int draw_wall(struct display *ds)
{
    t_bunny_accurate_position wallpx;
    t_bunny_positioget_position tmp;

    wallpx.x = 0;
    wallpx.y = 0;
    while (wallpx.y <= ds->ymax) {
        while (wallpx.x <= ds->xmax) {
                printf("%dx\n", tmp.x);
                printf("%dy\n", tmp.y);
            if (get_position(ds, wallpx) == 1) {
                tmp = pos_from_accurate(&wallpx);
                put_pixel(&tmp, ds->ds_px, ds->wall);
            } else if (get_position(ds, wallpx) == 0) {
                tmp = pos_from_accurate(&wallpx);
                put_pixel(&tmp, ds->ds_px, ds->floor);
            }
            wallpx.x += 1;
        }
        wallpx.x = 0;
        wallpx.y += 1;
    }
    blit_at_origin(ds);
    return (0);
}


