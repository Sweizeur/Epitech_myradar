/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** fjdsgkjdfg
*/

#include "my.h"


int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int j = 0;

    while (s1[i] != '\0' && s2[j] != '\0') {
        if (s1[i] != s2[j])
            return (s1[i] - s2[j]);
        i++;
        j++;
        if (i == n)
            return (0);
    }
    return (0);
}
