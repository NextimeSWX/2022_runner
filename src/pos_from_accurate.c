/*
 * E89 Pedagogical & Technical Lab
 * project:     tp laser
 * created on:  2023-01-17 - 11:53 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: pos_from_accurate.c
 */

#include "stu.h"

t_bunny_position pos_from_accurate(const t_accurate_pos *conv)
{
    t_bunny_position posa;

    posa.x = conv->x;
    posa.y = conv->y;
    return (posa);
}
