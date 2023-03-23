/*
 * E89 Pedagogical & Technical Lab
 * project:     convert
 * created on:  2023-03-01 - 09:58 +0100
 * 1st author:  nolan.vollet - nolan.vollet
 * description: convert to pos
 */

#include "stu.h"

int convert (struct display *map, t_accurate_pos *pos)
{
    int i;

    i = ((int)pos->y / map->tile_size) + ((int)pos->x / map->tile_size);
    return (i);
}
