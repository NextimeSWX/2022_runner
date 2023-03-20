
/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-13 - 10:48 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: rotate.c
 */

#include "stu.h"

t_bunny_response key_rotate(t_bunny_event_state state,
                           t_bunny_keysym keycode,
                           void *data)
{
    struct display *ds;

    ds = data;
    if (state == GO_UP)
        return (GO_ON);
    if (keycode == BKS_ESCAPE)
        return (EXIT_ON_SUCCESS);

    if (keycode == BKS_A) {
        LEFT_key(ds);
    }
    else if (keycode == BKS_E) {
        RIGHT_key(ds);
    }
    return (GO_ON);
}
