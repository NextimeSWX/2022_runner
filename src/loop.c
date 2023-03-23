/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2022-09-29 - 14:39 +0200
 * 1st author:  Élise C. Philippe - eriizu
 * description: loop.c
 */

#include <lapin.h>

struct gfx_context {
    t_bunny_window *ctx_win;
    t_bunny_pixelarray *ctx_px;
};

union color {
    unsigned int co_full;
    unsigned char co_rgba[4];
};

void blit_at_origin(struct gfx_context *ds)
{
    t_bunny_position pos;

    pos.x = 0;
    pos.y = 0;
    bunny_blit(&ds->ctx_win->buffer, &ds->ctx_px->clipable, &pos);
    bunny_display(ds->ctx_win);
}

_bunny_response loop(void *data)
{
    struct gfx_context *context;
    const bool *keys;
    union color color;

    color.co_full = BLACK;
    context = data;
    keys = bunny_get_keyboard();
    if (keys[BKS_Z]) {
        color.co_rgba[0] = 255;
    }
    if (keys[BKS_S]) {
        color.co_rgba[1] = 255;
    }
    my_clear_px(context->ctx_px, color.co_full);
    blit_at_origin(context);
    return (GO_ON);
}
