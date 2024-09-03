/*
** EPITECH PROJECT, 2024
** My_radar [WSL : Fedora]
** File description:
** check_collision
*/

#include "../include/structures.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Types.h>
#include <math.h>

static int check_collision1(global_t *ALL, int i, int j)
{
    int distance = sqrt(pow(PLANES[i].pos.x - PLANES[j].pos.x, 2) +
    pow(PLANES[i].pos.y - PLANES[j].pos.y, 2));

    return (
    distance <= ((PLANES[i].size.x * PLANES[i].scale.x / 2) +
    (PLANES[j].size.x * PLANES[j].scale.x / 2)) &&
    PLANES[i].is_alive == 1 && PLANES[j].is_alive == 1 &&
    PLANES[i].is_in_tower == 0 && PLANES[j].is_in_tower == 0 &&
    PLANES[i].altitude == PLANES[j].altitude) ? 1 : 0;
}

static void more_check_collision(global_t *ALL, int i)
{
    for (int j = i + 1; j < PLANES_COUNT; j++) {
        if (check_collision1(ALL, i, j) == 1) {
            PLANES[i].is_alive = 0;
            PLANES[j].is_alive = 0;
            PLANES[i].draw = 0;
        }
    }
}

void check_collision(global_t *ALL, int i)
{
    int distance = 0;
    int is_in_any_tower = 0;

    for (int j = 0; j < TOWERS_COUNT; j++) {
        distance = sqrt(pow(PLANES[i].pos.x - TOWERS[j].pos.x, 2) +
        pow(PLANES[i].pos.y - TOWERS[j].pos.y, 2));
        if (distance <= ((TOWERS[j].circle.radius * 0.01) * SIZE[0]) &&
        PLANES[i].is_alive == 1) {
            PLANES[i].is_in_tower = 1;
            sfRectangleShape_setOutlineColor(PLANES[i].rect.shape, sfBlack);
            is_in_any_tower = 1;
        }
    }
    if (is_in_any_tower == 0 && PLANES[i].is_alive == 1) {
        sfRectangleShape_setOutlineColor(PLANES[i].rect.shape, sfRed);
        PLANES[i].is_in_tower = 0;
    }
    more_check_collision(ALL, i);
}
