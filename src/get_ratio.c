/*
 * E89 Pedagogical & Technical Lab
 * project:     Radar
 * created on:  2023-01-20 - 11:19 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: get_ratio.c
 */

#include "stu.h"

float get_ratio(int a, int b, int x)
{
    float z;

    z = (float) (x - a) / (b - a);
    return (z);
}
