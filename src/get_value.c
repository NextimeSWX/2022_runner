/*
 * E89 Pedagogical & Technical Lab
 * project:     Radar
 * created on:  2023-01-20 - 11:20 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: get_value.c
 */

#include "stu.h"

int get_value(int a, int b, float r)
{
    float x;

    x = r * (b - a) + a;
    return (x);
}
