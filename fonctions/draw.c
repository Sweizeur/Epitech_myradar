/*
** EPITECH PROJECT, 2024
** My_radar [WSL : Fedora]
** File description:
** draw
*/

#include "../include/structures.h"

void drawallsprites(global_t *ALL)
{
    for (int i = 0; i < SPRITES_COUNT; i++) {
        sfRenderWindow_drawSprite(WIN, SPRITES[i].sprite, NULL);
    }
}

void drawallplanes(global_t *ALL)
{
    for (int i = 0; i < PLANES_COUNT; i++) {
        if (PLANES[i].is_alive == 1 && PLANES[i].draw == 1)
            sfRenderWindow_drawSprite(WIN, PLANES[i].sprite, NULL);
        if (HITBOX == 1 && PLANES[i].is_alive == 1 && PLANES[i].draw == 1) {
            sfRenderWindow_drawRectangleShape(WIN, PLANES[i].rect.shape, NULL);
            sfRectangleShape_setPosition(PLANES[i].rect.shape, (sfVector2f) {
            PLANES[i].pos.x, PLANES[i].pos.y});
        }
    }
}

void drawalltowers(global_t *ALL)
{
    for (int i = 0; i < TOWERS_COUNT; i++) {
        sfRenderWindow_drawSprite(WIN, TOWERS[i].sprite, NULL);
        if (HITBOX == 1) {
            sfCircleShape_setRadius(TOWERS[i].circle.shape,
            ((TOWERS[i].circle.radius * 0.01) * SIZE[0]));
            sfRenderWindow_drawCircleShape(WIN, TOWERS[i].circle.shape, NULL);
            sfCircleShape_setPosition(TOWERS[i].circle.shape, (sfVector2f) {
            TOWERS[i].pos.x - ((TOWERS[i].circle.radius * 0.01) * SIZE[0]),
            TOWERS[i].pos.y - ((TOWERS[i].circle.radius * 0.01) * SIZE[0])});
            TOWERS[i].circle.pos = sfCircleShape_getPosition(
                TOWERS[i].circle.shape);
        }
    }
}
