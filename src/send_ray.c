/*
 * E89 Pedagogical & Technical Lab
 * project:     sent ray
 * created on:  2023-01-19 - 10:44 +0100
 * 1st author:  nolan.vollet - nolan.vollet
 * description: sent a ray
 */

#include "stu.h"

int send_ray(struct display *ds,
                 float deg)
{
    t_bunny_accurate_position pos;
    t_bunny_position tmp;
    double rad;
    int i;

    i = 0;
    pos.y = ds->player.y;
    pos.x = ds->player.x;
    rad = deg_to_rads(deg);
    tmp = pos_from_accurate(&pos);
    while (get_position(ds, tmp) != 1) {
        pos = move_forward(&pos, rad, 1);
        tmp = pos_from_accurate(&pos);
        i += 1;
    }
    return (i);
}

