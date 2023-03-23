/*
 * E89 Pedagogical & Technical Lab
 * project:     sent ray
 * created on:  2023-01-19 - 10:44 +0100
 * 1st author:  nolan.vollet - nolan.vollet
 * description: sent a ray
 */

#include "stu.h"

t_accurate_pos send_ray(struct display *map,
                        const t_accurate_pos *start,
                        double angle)
{
    t_accurate_pos pos;
    int tile;
    double i;

    pos.y = start->y;
    pos.x = start->x;
    tile = convert(map, &pos);
    i = 0;
    if (map->map[tile] == 1) {
        return (pos);
    }
    else {
        while (map->map[tile] == 0
               && pos.x < map->xmax && pos.y < map->ymax) {
            pos = move_forward(start, angle, i);
            tile = convert(map, &pos);
            i += 0.5;
        }
        while (map->map[tile] == 1 && pos.x < map->xmax
               && pos.y < map->ymax) {
            pos = move_forward(start, angle, i);
            tile = convert(map, &pos);
            i -= 0.01;
        }
    }
    return (pos);
}
