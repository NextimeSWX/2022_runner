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

typedef t_bunny_accurate_position t_accurate_pos;

struct display {
    t_bunny_window     *ds_win;
    t_bunny_pixelarray *ds_px;
    t_accurate_pos      player;
    int                 walk;
    int                *map;
    double              fov;
    float               angle;
    int                 tile_size;
    int                 width;
    int                 height;
    int                 wall;
    int                 floor;
    int                 pixel;
    int                 xmax;
    int                 ymax;
};

int draw_wall(struct display *ds);
int  get_position(struct display *data, t_bunny_position position);
void z_key(struct display *data);
void s_key(struct display *data);
void q_key(struct display *data);
void d_key(struct display *data);
void left_key(struct display *data);
void right_key(struct display *data);
void put_pixel(t_bunny_position *,
               t_bunny_pixelarray *px,unsigned int color);
t_accurate_pos move_forward(const t_accurate_pos *start,
                            double angle, double len);
double deg_to_rads(double degrees);
t_bunny_position pos_from_accurate(const t_accurate_pos *conv);
void send_ray_len(struct display *ds, float deg, unsigned int color);
int send_ray(struct display *ds, float deg);
t_accurate_pos move_forward(const t_accurate_pos *start,
                            double angle,double len);
float get_ratio(int a, int b, int x);
float get_value(int a, int b, float r);
void fov(struct display *ds);
void draw_3d(struct display *ds, float len, int xpos, double angle);
void draw(struct display *ds, unsigned int color);

#endif
