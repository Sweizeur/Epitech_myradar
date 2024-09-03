/*
** EPITECH PROJECT, 2023
** Default
** File description:
** myhunter
*/

#include "include/structures.h"
#include "include/my.h"

void start(global_t *ALL)
{
    while (sfRenderWindow_isOpen(WIN)) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT));
        FPS += 1;
        move(&CLOCKS[0].time, &CLOCKS[0].seconds, CLOCKS[0].clock, ALL);
        timer_fps(&CLOCKS[1].time, &CLOCKS[1].seconds, CLOCKS[1].clock, ALL);
        sfRenderWindow_clear(WIN, sfBlack);
        if (ALL->local.draw == 1) {
            drawallsprites(ALL);
            drawallplanes(ALL);
            drawalltowers(ALL);
        }
        sfRenderWindow_drawText(WIN, TEXTS[0].text, NULL);
        sfRenderWindow_drawText(WIN, TEXTS[1].text, NULL);
        sfRenderWindow_display(WIN);
        keys(ALL);
        resize(ALL);
        death_plane(ALL);
        if (EVENT.type == sfEvtClosed)
            close_all(ALL);
    }
}

static void print_help(void)
{
    my_printf("Air traffic simulation panel. (in 3D space)\n\n");
    my_printf("USAGE\n\t./my_radar PATH_TO_SCRIPT\n\n");
    my_printf("OPTIONS\n\t-h\tprint the usage and quit.\n\n");
    my_printf("USER INTERACTIONS\n");
    my_printf("\t'L'\tdisplay hitboxes.\n");
    my_printf("\t'S'\tdisplay sprites.\n");
    my_printf("\t'LEFT'\tdecrease simulation speed.\n");
    my_printf("\t'RIGHT'\tincrease simulation speed.\n");
}

static int print_error(int nb, char **av)
{
    switch (nb) {
        case 1:
            my_printf("%s: error: no display variable set\n", av[0]);
            my_printf("retry with valid display variable\n");
            break;
        case 2:
            my_printf("%s: error: invalid path to script\n", av[0]);
            my_printf("retry with -h\n");
            break;
        case 3:
            my_printf("%s: error: invalid number of arguments\n", av[0]);
            my_printf("retry with -h\n");
            break;
    }
    return (84);
}

int main(int ac, char **av, char **env)
{
    global_t ALL;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_help();
        return (0);
    }
    for (int i = 0; env[i] != NULL; i++)
        if (my_strncmp(env[i], "DISPLAY", 7) == 0)
            ALL.local.display = 1;
    if (ALL.local.display == 0)
        return (print_error(1, av));
    if (ac == 2 && my_strcmp(av[1], "-h") != 0) {
        if (parcing(av[1], &ALL) == 84)
            return (print_error(2, av));
    }
    if (ac != 2) {
        return (print_error(3, av));
    }
    start(&ALL);
    sfRenderWindow_destroy(ALL.settings.window);
    return (0);
}
