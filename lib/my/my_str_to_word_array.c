/*
** EPITECH PROJECT, 2023
** Default
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my.h"

static void more_str_to_word_array(char ***tab1, int *j, int *k)
{
    (*tab1)[*j][*k] = '\0';
    *j = *j + 1;
    *k = 0;
}

char **my_str_to_word_array(char *str, char c)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **tab = malloc(sizeof(char *) * (my_strlen(str) + 1));

    tab[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\0') {
        if (str[i] == c) {
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
