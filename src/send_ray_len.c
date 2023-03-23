/*
 * E89 Pedagogical & Technical Lab
 * project:     sent ray
 * created on:  2023-01-19 - 10:44 +0100
 * 1st author:  nolan.vollet - nolan.vollet
 * description: sent a ray
 */

#include "stu.h"

int send_ray_len(struct display *map,
                 const t_accurate_pos *start,
                 unsigned int color)
{
    t_bunny_accurate_position pos;
    t_bunny_position tmp;
    double rad;
    double i;

    i = 0;
    pos.y = start->y;
    pos.x = start->x;
    rad = deg_to_rads(map->angle);
    tmp = pos_from_accurate(&pos);
    while (get_position(map, tmp) != 1
           && pos.x < map->xmax && pos.y < map->ymax) {
        pos = move_forward(&pos, rad, 0.5);
        put_pixel(&tmp, map->ds_px, color);
        tmp = pos_from_accurate(&pos);
        i += 0.5;
    }
    while (get_position(map, tmp) == 1
           && pos.x < map->xmax && pos.y < map->ymax) {
        pos = move_forward(&pos, (rad - M_PI), 0.01);
        put_pixel(&tmp, map->ds_px, map->wall);
        tmp = pos_from_accurate(&pos);
        i -= 0.01;
    }
    return (i);
}

