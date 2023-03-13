/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_laser
 * created on:  2022-11-22 - 09:48 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: stu.h
 */

#ifndef STU_H_
#define STU_H_

#include <math.h>
#include <lapin.h>
#include <assert.h>
#include <stdlib.h>

struct display {
    t_bunny_window *ds_win;
    t_bunny_pixelarray *ds_px;
    t_bunny_position player;
    int tile_size;
    int walk;
    int width;
    int height;
    int *map;
    int wall;
    int floor;
    int pixel;
    int xmax;
    int ymax;
};

typedef t_bunny_accurate_position t_accurate_pos;

int clear_pixelwall(struct display *ds);
int get_position(struct display *data, t_bunny_position position);
int Z_key(struct display *data);
int S_key(struct display *data);
int Q_key(struct display *data);
int D_key(struct display *data);
void stu_clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color);
void put_pixel(t_bunny_position *, t_bunny_pixelarray *px, unsigned int color);

#endif
