/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** teleport
*/

#include "my_rpg.h"
#include "my_struct.h"

void teleport_to_previous_pos(game_t *game)
{
    game->hero_pos_text.x = game->old_hero_pos_text.x;
    game->hero_pos_text.y = game->old_hero_pos_text.y;
    game->map_pos.x = game->old_map_pos.x;
    game->map_pos.y = game->old_map_pos.y;
}

void teleport_to_mart(game_t *game)
{
    game->old_hero_pos_text = game->hero_pos_text;
    game->old_map_pos = game->map_pos;
    game->hero_pos_text.x = 1507;
    game->hero_pos_text.y = 215;
    game->map_pos.x = -3934;
    game->map_pos.y = -235;
}

void teleport_to_pokedex(game_t *game)
{
    game->old_hero_pos_text = game->hero_pos_text;
    game->old_map_pos = game->map_pos;
    game->hero_pos_text.x = 1983;
    game->hero_pos_text.y = 555;
    game->map_pos.x = -5360;
    game->map_pos.y = -1250;
}

void teleport_to_house(game_t *game)
{
    game->old_hero_pos_text = game->hero_pos_text;
    game->old_map_pos = game->map_pos;
    game->hero_pos_text.x = 2503;
    game->hero_pos_text.y = 225;
    game->map_pos.x = -6930;
    game->map_pos.y = -260;
}

void teleport_to_green_house(game_t *game)
{
    game->old_hero_pos_text = game->hero_pos_text;
    game->old_map_pos = game->map_pos;
    game->hero_pos_text.x = 2463;
    game->hero_pos_text.y = 610;
    game->map_pos.x = -6810;
    game->map_pos.y = -1420;
}
