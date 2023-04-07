/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-28 - 10:32 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: runner.c
 */

#include "stu.h"

void blit_at_origin(struct display *ds)
{
    t_bunny_position pos;

    pos.x = 0;
    pos.y = 0;
    bunny_blit(&ds->ds_win->buffer, &ds->ds_px->clipable, &pos);
    bunny_display(ds->ds_win);
}

t_bunny_response loop(void *data)
{
    struct display *ds;
    const bool *keys;

    ds   = data;
    keys = bunny_get_keyboard();
    send_ray_len(ds, ds->angle, ds->floor);
    if (keys[BKS_Z])
        z_key(ds);
    if (keys[BKS_S])
        s_key(ds);
    if (keys[BKS_Q])
        q_key(ds);
    else if (keys[BKS_D])
        d_key(ds);
    if (keys[BKS_LEFT])
        left_key(ds);
    else if (keys[BKS_RIGHT])
        right_key(ds);
    if (keys[BKS_LSHIFT])
        ds->walk = 4;
    else {
        ds->walk = 2;
    }
    draw(ds);
    blit_at_origin(ds);
    return (GO_ON);
}

t_bunny_response key_event(t_bunny_event_state state,
                           t_bunny_keysym keycode,
                           void *data)
{
    struct display *ds;

    ds = data;
    if (state == GO_UP)
        return (GO_ON);
    if (keycode == BKS_ESCAPE)
        return (EXIT_ON_SUCCESS);
    blit_at_origin(ds);
    return (GO_ON);
}

int main(void)
{
    struct display display;

    int mx[20 * 11] = {
        1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 1, 0, 0, 1, 1, 0 ,0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1,
        1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1,
        1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1,
        1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1,
        1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1,
        1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };

    display.map       = &mx[0];
    display.width     = 20;
    display.height    = 11;
    display.tile_size = 40;
    display.angle     = 90;
    display.fov       = 70 / 2;

    display.xmax      = display.width * display.tile_size;
    display.ymax      = display.height * display.tile_size;
    display.floor     = WHITE;
    display.wall      = BLACK;
    display.pixel     = BLACK;
    display.walk      = 3;
    //display.ds_win    = bunny_start(display.xmax, display.ymax,
    //                                false, "fl: Runner mini_map");
    display.ds_win    = bunny_start(display.xmax, display.ymax,
                                    false, "fl: Runner 3D");
    //display.ds_px     = bunny_new_pixelarray(display.xmax, display.ymax);
    display.ds_px   = bunny_new_pixelarray(display.xmax, display.ymax);
    display.player.x  = 5.5 * display.tile_size;
    display.player.y  = 0.5 * display.tile_size;

    //draw_wall(&display);
    blit_at_origin(&display);
    bunny_set_key_response(key_event);
    bunny_set_loop_main_function(loop);
    draw_wall(&display);
    bunny_loop(display.ds_win, 30, &display);
    bunny_stop(display.ds_win);
    //bunny_loop(display.ds_win3d, 30, &display);
    //bunny_stop(display.ds_win3d);
}
