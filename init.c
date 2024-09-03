/*
** EPITECH PROJECT, 2023
** Default
** File description:
** myhunter
*/

#include "include/structures.h"

static void init_window(global_t *ALL)
{
    SIZE[0] = 1920;
    SIZE[1] = 1080;
    MODE = (sfVideoMode){SIZE[0], SIZE[1], 32};
    WIN = sfRenderWindow_create(MODE, "myhunter", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(WIN, 240);
}

static void load_background(global_t *ALL)
{
    SPRITES[0].texture = sfTexture_createFromFile("src/map.png", NULL);
    SPRITES[0].sprite = sfSprite_create();
    SPRITES[0].pos = (sfVector2f){(int) SIZE[0] / 2, (int) SIZE[1] / 2};
    sfSprite_setTexture(SPRITES[0].sprite, SPRITES[0].texture, sfTrue);
    sfSprite_setScale(SPRITES[0].sprite, (sfVector2f){1, 1});
    sfSprite_setOrigin(SPRITES[0].sprite, (sfVector2f){
        (int) sfTexture_getSize(SPRITES[0].texture).x / 2,
        (int) sfTexture_getSize(SPRITES[0].texture).y / 2});
    sfSprite_setPosition(SPRITES[0].sprite, (sfVector2f){
        SPRITES[0].pos.x, SPRITES[0].pos.y});
    SPRITES[0].size = sfTexture_getSize(SPRITES[0].texture);
    SPRITES[0].scale = sfSprite_getScale(SPRITES[0].sprite);
    SPRITES[0].origin = sfSprite_getOrigin(SPRITES[0].sprite);
    SPRITES[0].pos = sfSprite_getPosition(SPRITES[0].sprite);
}

static void load_timer(global_t *ALL)
{
    TEXTS[0].font = sfFont_createFromFile("src/font.ttf");
    TEXTS[0].text = sfText_create();
    TEXTS[0].size = 20;
    TEXTS[0].str = "0";
    sfText_setString(TEXTS[0].text, TEXTS[0].str);
    sfText_setFont(TEXTS[0].text, TEXTS[0].font);
    sfText_setCharacterSize(TEXTS[0].text, TEXTS[0].size);
    sfText_setPosition(TEXTS[0].text, (sfVector2f){SIZE[0] - 70, 20});
    TEXTS[0].pos = sfText_getPosition(TEXTS[0].text);
    TEXTS[0].scale = sfText_getScale(TEXTS[0].text);
}

static void load_fps(global_t *ALL)
{
    TEXTS[1].font = sfFont_createFromFile("src/font.ttf");
    TEXTS[1].text = sfText_create();
    TEXTS[1].size = 15;
    TEXTS[1].str = "0";
    sfText_setString(TEXTS[1].text, TEXTS[1].str);
    sfText_setFont(TEXTS[1].text, TEXTS[1].font);
    sfText_setCharacterSize(TEXTS[1].text, TEXTS[1].size);
    sfText_setPosition(TEXTS[1].text, (sfVector2f){20, 20});
    TEXTS[1].pos = sfText_getPosition(TEXTS[1].text);
    TEXTS[1].scale = sfText_getScale(TEXTS[1].text);
}

static void load_settings(global_t *ALL)
{
    SPRITES_COUNT = 1;
    CLOCKS_COUNT = 2;
    TEXTS_COUNT = 2;
    DATA_COUNT = 2;
    HITBOX = 1;
    TIMER = 0;
    FPS = 0;
    ALL->local.speed = 0;
    ALL->local.death_count = 0;
    ALL->local.draw = 1;
    ALL->local.display = 0;
    SPRITES = malloc(sizeof(sprites_t) * SPRITES_COUNT);
    PLANES = malloc(sizeof(planes_t) * PLANES_COUNT);
    TOWERS = malloc(sizeof(towers_t) * TOWERS_COUNT);
    CLOCKS = malloc(sizeof(clocks_t) * CLOCKS_COUNT);
    TEXTS = malloc(sizeof(texts_t) * TEXTS_COUNT);
    SPRITEDATA = malloc(sizeof(spritedata_t) * DATA_COUNT);
}

void init(global_t *ALL, int i)
{
    load_settings(ALL);
    if (i == 0)
        init_window(ALL);
    load_background(ALL);
    for (int nb = 0; nb < CLOCKS_COUNT; nb++)
        CLOCKS[nb].clock = sfClock_create();
    load_timer(ALL);
    load_fps(ALL);
}
