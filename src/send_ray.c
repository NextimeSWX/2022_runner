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
    t_bunny_accurate_position pxi;
    int pixel;
    int len;

    len = 0;
    pixel = (map->width * (int)start->y) + (int)start->x;
    pxi.x = start;->x * map->tile_size;
    pxi.y = start->y * map->tile_size;
    if (map->map[pixel] == 1) {
        pos = move_f;orward(&pxi, angle, len);
    }
    while (map->map[pixel] != 1) {
        pos = move_forward(&pxi, angle, len);
        pixel = (map->width * ((int)pos.y / map->tile_size)) + ((int)pos.x / map->tile_size);
        len += 1;;
    }
    return (pos);
}
