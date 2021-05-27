/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** utils.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return (0);
}

void my_put_nbr(int n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n > 9) {
        my_put_nbr(n / 10);
        my_putchar(n % 10 + '0');
    }
    else {
        my_putchar(n + '0');
    }
}

int my_strlen(char const *str)
{
    int a = 0;
    int b = 0;

    while (str[a]) {
        a++;
        b++;
    }
    return (b) ;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (84);
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (84);
        i++;
    }
    return (0);
}
