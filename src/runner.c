/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-28 - 10:32 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: runner.c
 */

#include <stdio.h>
#include "stu.h"

void blit_at_origin(struct display *ds)
{
    t_bunny_position pos;

    pos.x = 0;
    pos.y = 0;
    bunny_blit(&ds->ds_win->buffer, &ds->ds_px->clipable, &pos);
    bunny_display(ds->ds_win);
}

t_bunny_response key_event(t_bunny_event_state state,
                           t_bunny_keysym keycode,
                           void *data)
{
    struct display *ds;
    t_bunny_position tmp;

    ds = data;
    tmp = pos_from_accurate(&ds->player);
    put_pixel(&tmp, ds->ds_px, WHITE);
    if (state == GO_UP)
        return (GO_ON);
    if (keycode == BKS_ESCAPE)
        return (EXIT_ON_SUCCESS);
    if (keycode == BKS_LEFT) {
        left_key(ds);
    }
    else if (keycode == BKS_RIGHT) {
        right_key(ds);
    }
    if (keycode == BKS_Z) {
        printf("%d\n", ds->angle);
        z_key(ds);
    }
    else if (keycode == BKS_S) {
        s_key(ds);
    }
    else if (keycode == BKS_Q) {
        q_key(ds);
    }
    else if (keycode == BKS_D) {
        d_key(ds);
    }
    //put_pixel(pos_from_accurate(ds->player), ds->ds_px, ds->pixel);
    blit_at_origin(ds);
    return (GO_ON);
}

int main(void)
{
    struct display display;
    /*
      int mx[15 * 10] = {
      1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 0, 0, 1, 0, 0, 1, 1, 0 ,0, 0, 0, 0, 1, 1,
      1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1,
      1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1,
      1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1,
      1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
      1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
      1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
      1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
      };*/

    int mx[15 * 10] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    display.map     = &mx[0];
    display.width     = 15;
    display.height    = 10;
    display.tile_size = 50;
    display.angle = 270;

    display.xmax      = display.width * display.tile_size;
    display.ymax      = display.height * display.tile_size;
    display.floor = BLACK;
    display.wall = BLACK;
    display.pixel = WHITE;
    display.walk = 5;
    display.ds_win = bunny_start(display.xmax, display.ymax, false, "fl: tp event");
    display.ds_px = bunny_new_pixelarray(display.xmax, display.ymax);
    stu_clear_pixelarray(display.ds_px, display.floor);
    display.player.x = 275;
    display.player.y = 25;
    blit_at_origin(&display);
    clear_pixelwall(&display);

    bunny_set_key_response(key_event);
    bunny_loop(display.ds_win, 30, &display);
    bunny_stop(display.ds_win);
    return (0);
}
