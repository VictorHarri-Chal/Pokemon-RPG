/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** main.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

int main(int ac, char **av)
{
    (void) av;

    if (ac != 1)
        return (84);
    return (my_rpg());
}
