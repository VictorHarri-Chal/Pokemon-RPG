/*
** EPITECH PROJECT, 2021
** create_fight.c
** File description:
** create_fight
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void set_arrow_box(fight_t *fight)
{
    fight->pos_arrow.x = 580.0;
    fight->pos_arrow.y = 550.0;
    fight->text_arrow_box = \
    sfTexture_createFromFile("assets/fight/asset_fight.png", NULL);
    fight->sp_arrow_box = sfSprite_create();
    sfSprite_setTexture(fight->sp_arrow_box, fight->text_arrow_box, sfTrue);
    sfSprite_setPosition(fight->sp_arrow_box, fight->pos_arrow);
    sfVector2f scale = {4.52, 4.69};
    sfSprite_setScale(fight->sp_arrow_box, scale);
    sfSprite_setTextureRect(fight->sp_arrow_box, (sfIntRect) { 269, 4, 5, 9 });
}

void set_playable_box(fight_t *fight)
{
    fight->text_playable_box = \
    sfTexture_createFromFile("assets/fight/asset_fight.png", NULL);
    fight->sp_playable_box = sfSprite_create();
    sfSprite_setTexture(fight->sp_playable_box, \
    fight->text_playable_box, sfTrue);
    sfSprite_setPosition(fight->sp_playable_box, (sfVector2f) { 545, 500 });
    sfVector2f scale = {4.52, 4.69};
    sfSprite_setScale(fight->sp_playable_box, scale);
    sfSprite_setTextureRect(fight->sp_playable_box, \
    (sfIntRect) { 147, 5, 119, 47 });
}