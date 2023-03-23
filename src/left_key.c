/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-07 - 10:08 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: LEFT_key.c
 */

#include "stu.h"

void left_key(struct display *ds)
{
    ds->angle -= 45;
}

