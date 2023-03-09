/*
 * E89 Pedagogical & Technical Lab
 * project:     Draw line
 * created on:  2022-11-07 - 11:07 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: put_pixel.c
 */

#include "stu.h"

void put_pixel(t_bunny_position *pos,
               t_bunny_pixelarray *px,
               unsigned int color)
{
    unsigned int *tmp;
    int width;
    int height;
    int i;

    i = 0;
    width = px->clipable.clip_width;
    height = px->clipable.clip_height;
    tmp = (unsigned int *) px->pixels;
    i = (width * pos->y) + pos->x;
    if (i >= 0 && i < height * width) {
        tmp[i] = color;
    }
}
