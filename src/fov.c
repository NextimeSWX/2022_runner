/*
 * E89 Pedagogical & Technical Lab
 * project:     Runner
 * created on:  2023-03-24 - 15:43 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: fov.c
 */

#include "stu.h"

void fov(struct display *ds)
{
    double deg;
    int i;

    i = 0;
    deg = 0;
    while (i < ds->xmax) {
        deg = get_value((ds->angle - ds->fov), (ds->angle + ds->fov),
                        get_ratio(0, ds->xmax, i));
        draw_3d(ds, send_ray(ds, deg), i, deg);
        i += 1;
    }
}
