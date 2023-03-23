/*
 * E89 Pedagogical & Technical Lab
 * project:     draw impact
 * created on:  2023-01-19 - 10:46 +0100
 * 1st author:  nolan.vollet - nolan.vollet
 * description: draw the impact point
 */

#include "stu.h"

void draw_impact(struct display *map,
                 t_bunny_pixelarray *pxa,
                 const t_accurate_pos *start,
                 double angle)
{
    t_bunny_position pos;
    t_bunny_accurate_position posi;

    posi = send_ray(map,start,angle);
    pos = pos_from_accurate(&posi);
    put_pixel(&pos,pxa, RED);
}
