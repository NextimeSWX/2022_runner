/*
 * E89 Pedagogical & Technical Lab
 * project:     rayon
 * created on:  2023-01-17 - 11:53 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: move_forward.c
 */

#include "stu.h"

t_accurate_pos move_forward(const t_accurate_pos *start,
                             double angle,
                             double len)
{
    t_bunny_accurate_position move;

    move.x = (cos(angle) * len) + start->x;
    move.y = (sin(angle) * len) + start->y;
    return (move);
}
