/*
** EPITECH PROJECT, 2024
** My_radar [WSL : Fedora]
** File description:
** moveplane
*/

#include "../include/structures.h"

static void check_end_angle(global_t *ALL, int i, float x, float y)
{
    float angle;

    if ((fabs(PLANES[i].pos.x - PLANES[i].end.x) <= fabs(x * PLANES[i].speed)
    && fabs(PLANES[i].pos.y - PLANES[i].end.y) <= fabs(y * PLANES[i].speed))
    && PLANES[i].is_alive == 1 && PLANES[i].draw == 1) {
        PLANES[i].is_alive = 0;
        PLANES[i].draw = 0;
    }
    angle = atan2(y, x) * 180 / M_PI;
    if (PLANES[i].is_alive == 1 && PLANES[i].draw == 1) {
        sfSprite_setRotation(PLANES[i].sprite, angle);
        sfRectangleShape_setRotation(PLANES[i].rect.shape, angle);
    }
}

void move_plane(global_t *ALL, int i)
{
    float speed = (PLANES[i].speed * 0.05) + ALL->local.speed;
    float x = PLANES[i].end.x - PLANES[i].pos.x;
    float y = PLANES[i].end.y - PLANES[i].pos.y;
    float distance = sqrt(pow(x, 2) + pow(y, 2));

    if (distance > 0) {
        x = x / distance;
        y = y / distance;
    }
    if (PLANES[i].is_alive == 1 && PLANES[i].draw == 1) {
        PLANES[i].pos.x += x * speed;
        PLANES[i].pos.y += y * speed;
        sfSprite_setPosition(PLANES[i].sprite, PLANES[i].pos);
    }
    check_end_angle(ALL, i, x, y);
}
