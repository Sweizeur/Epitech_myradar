/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** fjdsgkjdfg
*/

#include "my.h"
#include <stdio.h>

int my_is_prime(int nb)
{
    if (nb == 1 || nb == 0 || nb < 0) {
        return (0);
    }
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0) {
            return (0);
        }
    }
    return (1);
}
