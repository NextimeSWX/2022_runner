/*
 * E89 Pedagogical & Technical Lab
 * project:     sent ray
 * created on:  2023-01-19 - 10:44 +0100
 * 1st author:  nolan.vollet - nolan.vollet
 * description: sent a ray
 */

#include "stu.h"

void send_ray_len(struct display *ds,
                 float deg,
                 unsigned int color)
{
    t_bunny_accurate_position pos;
    t_bunny_position tmp;
    double rad;
    double i;

    i = 0;
    pos.x = ds->player.x;
    pos.y = ds->player.y;
    rad = deg_to_rads(deg);
    tmp = pos_from_accurate(&pos);
    while (get_position(ds, tmp) != 1
           && pos.x <= ds->xmax && pos.y <= ds->ymax
           && pos.x >= 0 && pos.y >= 0) {
        tmp.x /= 4;
        tmp.y /= 4;
        pos = move_forward(&pos, rad, 1);
        put_pixel(&tmp, ds->ds_px, color);
        tmp = pos_from_accurate(&pos);
        i += 1;
    }
}
