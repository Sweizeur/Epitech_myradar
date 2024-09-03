/*
** EPITECH PROJECT, 2023
** Default
** File description:
** my_printtab
*/

#include "my.h"
#include <stdlib.h>

void my_printtab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
}
