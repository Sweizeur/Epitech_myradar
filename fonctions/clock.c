/*
** EPITECH PROJECT, 2024
** My_radar [WSL : Fedora]
** File description:
** clock
*/

#include "../include/structures.h"
#include "../include/my.h"

static void draw_plane(global_t *ALL)
{
    for (int i = 0; i < PLANES_COUNT; i++)
        if (PLANES[i].delay == TIMER)
            PLANES[i].draw = 1;
}

void move(sfTime *time, float *seconds, sfClock *clock, global_t *ALL)
{
    *time = sfClock_getElapsedTime(clock);
    *seconds = time->microseconds / 1000000.0;
    if (*seconds > 0.01) {
        for (int i = 0; i < PLANES_COUNT; i++) {
            move_plane(ALL, i);
            check_collision(ALL, i);
        }
        sfClock_restart(clock);
    }
}

void timer_fps(sfTime *time, float *seconds, sfClock *clock, global_t *ALL)
{
    *time = sfClock_getElapsedTime(clock);
    *seconds = time->microseconds / 1000000.0;
    if (*seconds > 1) {
        draw_plane(ALL);
        TEXTS[0].str = my_nbr_to_str(TIMER);
        sfText_setString(TEXTS[0].text, TEXTS[0].str);
        TEXTS[1].str = my_nbr_to_str(FPS);
        sfText_setString(TEXTS[1].text, TEXTS[1].str);
        FPS = 0;
        TIMER += 1;
        sfClock_restart(clock);
    }
}
