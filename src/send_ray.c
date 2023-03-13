/*
 * E89 Pedagogical & Technical Lab
 * project:     rayon
 * created on:  2023-01-19 - 10:34 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: send_ray.c
 */

#include "stu.h"
#include "map.h"

t_accurate_pos send_ray(struct map *map,
                        const t_accurate_pos *start,
                        double angle)
{
    t_bunny_accurate_position pos;
    int pixel;
    double len;

    len = 0;
    pixel = (map->width * (int)start->y) + (int)start->x;
    if (map->map[pixel] == 1) {
        pos = *start;
    }
    while (map->map[pixel] != 1) {
        pos = move_forward(start, angle, len);
        pixel = (map->width * (int)pos.y) + (int)pos.x;
        len += 0.01;
    }
    return (pos);
}
