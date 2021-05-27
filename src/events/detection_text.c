/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** detection_text
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

int detect_text(all_t *all, int x, int y)
{
    if (all->game->map[y][x] == '1')
        return (0);
    if (all->game->map[y][x] == '2')
        return (1);
    if (all->game->map[y][x] == '3')
        return (2);
    if (all->game->map[y][x] == '4')
        return (3);
    if (all->game->map[y][x] == '5')
        return (4);
    if (all->game->map[y][x] == '6')
        return (5);
    if (all->game->map[y][x] == '7')
        return (6);
    if (all->game->map[y][x] == '8')
        return (7);
    return (-1);
}