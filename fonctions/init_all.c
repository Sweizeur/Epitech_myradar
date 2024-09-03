/*
** EPITECH PROJECT, 2024
** My_radar [WSL : Fedora]
** File description:
** init_all
*/

#include "../include/my.h"
#include "../include/structures.h"

static void more_load_planes1(global_t *ALL, int i, char **map)
{
    sfRectangleShape_setFillColor(PLANES[i].rect.shape, sfTransparent);
    sfRectangleShape_setOutlineColor(PLANES[i].rect.shape, sfBlack);
    sfRectangleShape_setOutlineThickness(PLANES[i].rect.shape, 2);
    PLANES[i].rect.pos = sfRectangleShape_getPosition(PLANES[i].rect.shape);
}

static void more_load_planes(global_t *ALL, int i, char **map)
{
    PLANES[i].pos = sfSprite_getPosition(PLANES[i].sprite);
    PLANES[i].start = PLANES[i].pos;
    PLANES[i].end = (sfVector2f){my_getnbr(map[3]),
    my_getnbr(map[4])};
    PLANES[i].speed = my_getnbr(map[5]);
    PLANES[i].delay = my_getnbr(map[6]);
    PLANES[i].is_alive = 1;
    PLANES[i].is_in_tower = 0;
    PLANES[i].draw = 0;
    PLANES[i].distance_from_tower = SIZE[0] + 1;
    PLANES[i].rect.shape = sfRectangleShape_create();
    PLANES[i].rect.size = (sfVector2f){PLANES[i].size.x * PLANES[i].scale.x,
        PLANES[i].size.y * PLANES[i].scale.y};
    sfRectangleShape_setOrigin(PLANES[i].rect.shape, (sfVector2f){
        PLANES[i].origin.x * PLANES[i].scale.x,
        PLANES[i].origin.y * PLANES[i].scale.y});
    sfRectangleShape_setSize(PLANES[i].rect.shape, PLANES[i].rect.size);
    more_load_planes1(ALL, i, map);
}

static void more_load_towers(global_t *ALL, int i, char **map)
{
    sfCircleShape_setRadius(TOWERS[i].circle.shape,
    ((TOWERS[i].circle.radius * 0.01) * SIZE[0]));
    sfCircleShape_setPosition(TOWERS[i].circle.shape, (sfVector2f) {
        TOWERS[i].pos.x - ((TOWERS[i].circle.radius * 0.01) * SIZE[0]),
        TOWERS[i].pos.y - ((TOWERS[i].circle.radius * 0.01) * SIZE[0])});
    sfCircleShape_setFillColor(TOWERS[i].circle.shape, sfTransparent);
    sfCircleShape_setOutlineColor(TOWERS[i].circle.shape, sfBlack);
    sfCircleShape_setOutlineThickness(TOWERS[i].circle.shape, 3);
    TOWERS[i].circle.pos = sfCircleShape_getPosition(TOWERS[i].circle.shape);
}

void load_planes(global_t *ALL, int i, char **map)
{
    int scale = my_rand(10, 20);

    PLANES[i].altitude = scale;
    PLANES[i].texture = sfTexture_createFromFile("src/plane.png", NULL);
    PLANES[i].sprite = sfSprite_create();
    PLANES[i].pos = (sfVector2f){my_getnbr(map[1]),
    my_getnbr(map[2])};
    sfSprite_setTexture(PLANES[i].sprite, PLANES[i].texture, sfTrue);
    sfSprite_setScale(PLANES[i].sprite, (sfVector2f){scale * 0.01,
    scale * 0.01});
    sfSprite_setOrigin(PLANES[i].sprite, (sfVector2f){
        (int) sfTexture_getSize(PLANES[i].texture).x / 2,
        (int) sfTexture_getSize(PLANES[i].texture).y / 2});
    sfSprite_setPosition(PLANES[i].sprite, (sfVector2f){
        PLANES[i].pos.x, PLANES[i].pos.y});
    PLANES[i].size = sfTexture_getSize(PLANES[i].texture);
    PLANES[i].scale = sfSprite_getScale(PLANES[i].sprite);
    PLANES[i].origin = sfSprite_getOrigin(PLANES[i].sprite);
    more_load_planes(ALL, i, map);
}

void load_towers(global_t *ALL, int i, char **map)
{
    TOWERS[i].texture = sfTexture_createFromFile("src/tower.png", NULL);
    TOWERS[i].sprite = sfSprite_create();
    TOWERS[i].pos = (sfVector2f){my_getnbr(map[1]),
    my_getnbr(map[2])};
    sfSprite_setTexture(TOWERS[i].sprite, TOWERS[i].texture, sfTrue);
    sfSprite_setScale(TOWERS[i].sprite, (sfVector2f){0.1, 0.1});
    sfSprite_setOrigin(TOWERS[i].sprite, (sfVector2f){
        (int) sfTexture_getSize(TOWERS[i].texture).x / 2,
        (int) sfTexture_getSize(TOWERS[i].texture).y / 2});
    sfSprite_setPosition(TOWERS[i].sprite, (sfVector2f){
        TOWERS[i].pos.x, TOWERS[i].pos.y});
    TOWERS[i].size = sfTexture_getSize(TOWERS[i].texture);
    TOWERS[i].scale = sfSprite_getScale(TOWERS[i].sprite);
    TOWERS[i].origin = sfSprite_getOrigin(TOWERS[i].sprite);
    TOWERS[i].pos = sfSprite_getPosition(TOWERS[i].sprite);
    TOWERS[i].circle.radius = my_getnbr(map[3]);
    TOWERS[i].circle.shape = sfCircleShape_create();
    more_load_towers(ALL, i, map);
}
