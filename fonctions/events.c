/*
** EPITECH PROJECT, 2023
** Sans titre(Espace de travail)
** File description:
** close
*/

#include "../include/structures.h"

static void close_all1(global_t *ALL)
{
    for (int i = 0; i < TOWERS_COUNT; i++) {
        sfTexture_destroy(TOWERS[i].texture);
        sfSprite_destroy(TOWERS[i].sprite);
        sfCircleShape_destroy(TOWERS[i].circle.shape);
    }
    for (int i = 0; i < CLOCKS_COUNT; i++) {
        sfClock_destroy(CLOCKS[i].clock);
    }
    for (int i = 0; i < TEXTS_COUNT; i++) {
        sfFont_destroy(TEXTS[i].font);
        sfText_destroy(TEXTS[i].text);
    }
    free(SPRITES);
    free(PLANES);
    free(TOWERS);
    free(CLOCKS);
    free(TEXTS);
    free(SPRITEDATA);
}

void close_all(global_t *ALL)
{
    sfRenderWindow_close(WIN);
    for (int i = 0; i < SPRITES_COUNT; i++) {
        sfTexture_destroy(SPRITES[i].texture);
        sfSprite_destroy(SPRITES[i].sprite);
    }
    for (int i = 0; i < PLANES_COUNT; i++) {
        sfTexture_destroy(PLANES[i].texture);
        sfSprite_destroy(PLANES[i].sprite);
        sfRectangleShape_destroy(PLANES[i].rect.shape);
    }
    close_all1(ALL);
}

void keys(global_t *ALL)
{
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyL) {
        HITBOX *= -1;
        EVENT.type = 1;
    }
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyS) {
        ALL->local.draw *= -1;
        EVENT.type = 1;
    }
    if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyLeft &&
    ALL->local.speed > -4) {
        ALL->local.speed -= 0.1;
        EVENT.type = 1;
    }
    if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyRight &&
    ALL->local.speed < 4) {
        ALL->local.speed += 0.1;
        EVENT.type = 1;
    }
}

void death_plane(global_t *ALL)
{
    for (int i = 0; i < PLANES_COUNT; i++) {
        if (PLANES[i].is_alive == 1)
            ALL->local.death_count += 1;
    }
    if (ALL->local.death_count == 0)
        close_all(ALL);
    ALL->local.death_count = 0;
}

void resize(global_t *ALL)
{
    if (EVENT.type == sfEvtResized && EVENT.size.width > 0 &&
    EVENT.size.height > 0) {
        SIZE[0] = EVENT.size.width;
        SIZE[1] = EVENT.size.height;
        EVENT.type = 1;
    }
}
