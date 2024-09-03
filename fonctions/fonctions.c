/*
** EPITECH PROJECT, 2024
** My_radar [WSL : Fedora]
** File description:
** random
*/

#include "../include/my.h"
#include <stdlib.h>

int my_rand(int min, int max)
{
    int nb = 0;

    nb = rand() % (max - min + 1) + min;
    return (nb);
}

static void more_str_to_word_array(char ***tab1, int *j, int *k)
{
    (*tab1)[*j][*k] = '\0';
    *j = *j + 1;
    *k = 0;
}

char **my_str_to_word_array1(char *str, char c1, char c2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **tab = malloc(sizeof(char *) * (my_strlen(str) + 1));

    tab[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\0') {
        if (str[i] == c1 || str[i] == c2) {
            more_str_to_word_array(&tab, &j, &k);
            tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
        } else {
            tab[j][k] = str[i];
            k++;
        }
        i++;
    }
    tab[j][k] = '\0';
    tab[j + 1] = NULL;
    return (tab);
}
