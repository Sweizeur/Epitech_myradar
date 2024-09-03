/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** fjdsgkjdfg
*/

#include "my.h"
#include <stdio.h>

static int my_sqrt1(int n, int val)
{
    if (n < 1) {
        return (0);
    }
    if ((n * n) == val) {
        return (n);
    }
    return (my_sqrt1((n - 1), val));
}

int my_compute_square_root(int n)
{
    return (my_sqrt1((n / 2), n));
}
