/*
** EPITECH PROJECT, 2024
** My_radar [WSL : Fedora]
** File description:
** my_sqrt
*/

double my_sqrt(double x)
{
    double div = x / 2;
    double res = x;

    while (res > div) {
        res = div;
        div = (x / div + div) / 2;
    }
    return (res);
}
