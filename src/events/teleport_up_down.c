/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** teleport_up_down
*/

#include "my_rpg.h"
#include "my_struct.h"

bool is_hero_at_teleport_up(int py, int px)
{
    if ((py >= 1503 && py <= 1505) && (px >= 289 && px <= 321))
        return (true);
    return (false);
}

bool is_hero_at_teleport_down(int py, int px)
{
    if ((py >= 1386 && py <= 1388) && (px >= 289 && px <= 321))
        return (true);
    return (false);
}

void teleport_up(game_t *game)
{
    game->hero_pos_text.y -= 125;
    game->map_pos.y += 125 * 3;
}

void teleport_down(game_t *game)
{
    game->hero_pos_text.y += 125;
    game->map_pos.y -= 125 * 3;
}
