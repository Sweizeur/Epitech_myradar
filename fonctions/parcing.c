/*
** EPITECH PROJECT, 2024
** My_radar [WSL : Fedora]
** File description:
** parcing
*/

#include "../include/structures.h"
#include "../include/my.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

static long sizefile(char *filepath)
{
    struct stat s;

    stat(filepath, &s);
    return (s.st_size);
}

static void boucle_store_by_letter(char ***dest, char **tmp, int nb)
{
    for (int j = 0; tmp[j] != NULL; j++) {
        dest[nb][j] = malloc(sizeof(char) * my_strlen(tmp[j]) + 1);
        dest[nb][j] = tmp[j];
    }
}

static char ***store_by_letter(char **map, char ***dest, char c)
{
    char **tmp = NULL;
    int i = 0;
    int nb = 0;

    dest = malloc(sizeof(char **) * my_tablen(map) + 1);
    for (i = 0; map[i] != NULL; i++) {
        if (map[i][0] == c) {
            tmp = my_str_to_word_array1(map[i], ' ', '\t');
            dest[nb] = malloc(sizeof(char *) * my_tablen(tmp) + 1);
            boucle_store_by_letter(dest, tmp, nb);
            dest[nb][my_tablen(tmp)] = NULL;
            nb++;
        }
    }
    dest[nb] = NULL;
    return dest;
}

static int my_tablen2(char ***tab)
{
    int i = 0;

    for (i; tab[i] != NULL; i++);
    return (i);
}

static int load_sprites(global_t *ALL, char ***planesmap, char ***towersmap)
{
    for (int nb = 0; nb < TOWERS_COUNT; nb++)
        load_towers(ALL, nb, towersmap[nb]);
    for (int nb = 0; nb < PLANES_COUNT; nb++)
        load_planes(ALL, nb, planesmap[nb]);
    return 0;
}

int parcing(char *filepath, global_t *ALL)
{
    char **map = NULL;
    char ***planesmap = NULL;
    char ***towersmap = NULL;
    int f = open(filepath, O_RDONLY);
    long size = sizefile(filepath);
    char *map_file = malloc(sizeof(char) * (size + 1));

    if (f == -1 || size == -1)
        return 84;
    read(f, map_file, size);
    if (map_file == NULL)
        return 84;
    map = my_str_to_word_array(map_file, '\n');
    towersmap = store_by_letter(map, towersmap, 'T');
    planesmap = store_by_letter(map, planesmap, 'A');
    PLANES_COUNT = my_tablen2(planesmap);
    TOWERS_COUNT = my_tablen2(towersmap);
    init(ALL, 0);
    return (load_sprites(ALL, planesmap, towersmap));
}
