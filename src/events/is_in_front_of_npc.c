/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** is_in_front_of_npc
*/

#include "my_rpg.h"
#include "my_struct.h"

bool is_in_front_of_npc(game_t *game)
{
    if (((game->hero_pos_text.x >= 1960 && \
        game->hero_pos_text.x <= 30 + 1970) && \
        (game->hero_pos_text.y >= 490 && \
        game->hero_pos_text.y <= 10 + 490)))
        return (true);
    return (false);
}
