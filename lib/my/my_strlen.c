/*
** EPITECH PROJECT, 2023
** day04
** File description:
** task03
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++);
    return (i);
}
