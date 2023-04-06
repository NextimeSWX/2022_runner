/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-04-05 - 09:51 +0200
 * 1st author:  evan.lebihan - evan.lebihan
 * description: 3d.c
 */

#include "stu.h"

t_bunny_position draw_3d_wall(struct display *ds,
                              t_bunny_position pos,
                              float resultat,
                              unsigned int color)
{
    int i;

    i = 0;
    while (i < resultat) {
        put_pixel(&pos, ds->ds_px, color);
        pos.y += 1;
        i += 1;
    }
    return (pos);
}

t_bunny_position draw_floor(struct display *ds,
                            t_bunny_position pos,
                            float resultat,
                            unsigned int color)
{
    int i;

    i = 0;
    while (i < (ds->ymax / 2) - (resultat / 2)) {
        put_pixel(&pos, ds->ds_px, color);
        pos.y += 1;
        i += 1;
    }
    return (pos);
}
void draw_3d(struct display *ds, float len, int xpos, double angle)
{
    float resultat;
    t_bunny_position pos;

    resultat = ds->ymax * ds->tile_size /
        (len * cos((deg_to_rads(ds->angle)) - deg_to_rads(angle)));
    pos.x = xpos;
    pos.y = 0;
    pos = draw_floor(ds, pos, resultat, BLUE);
    pos = draw_3d_wall(ds, pos, resultat, ds->wall);
    draw_floor(ds, pos, resultat, ds->floor);
}
