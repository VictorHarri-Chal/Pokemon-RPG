/*
** EPITECH PROJECT, 2021
** init_fight.c
** File description:
** init_fight
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

fight_t *set_text_fight(fight_t *fight)
{
    fight->texte_level_enemie = \
    set_info_text(fight->texte_level_enemie, (sfVector2f) { 380, 127 }, 40);
    fight->texte_level_player = \
    set_info_text(fight->texte_level_player, \
    (sfVector2f) { 980, 355 }, 40);
    fight->texte_name_enemie = \
    set_info_text(fight->texte_name_enemie, (sfVector2f) { 70, 127 }, 40);
    fight->texte_name_player = \
    set_info_text(fight->texte_name_player, (sfVector2f) { 670, 355 }, 40);
    fight->texte_hp_max = \
    set_info_text(fight->texte_hp_max, (sfVector2f) { 955, 430 }, 40);
    fight->texte_hp_actual = \
    set_info_text(fight->texte_hp_actual, (sfVector2f) { 895, 430 }, 40);
    set_text_fight2(fight);
    return (fight);
}

sfText *set_info_text(sfText *text, sfVector2f pos, int size)
{
    text = sfText_create();
    sfFont *font = \
    sfFont_createFromFile("assets/dialogue/pokemon_pixel_font.ttf");
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, size);
    sfFont_destroy(font);
    return (text);
}

void set_info(fight_t *fight)
{
    fight->text_info_enemie = \
    sfTexture_createFromFile("assets/fight/asset_fight.png", NULL);
    fight->sp_info_enemie = sfSprite_create();
    fight->text_info_player = \
    sfTexture_createFromFile("assets/fight/asset_fight.png", NULL);
    fight->sp_info_player = sfSprite_create();
    sfSprite_setTexture(fight->sp_info_enemie, fight->text_info_enemie, sfTrue);
    sfSprite_setPosition(fight->sp_info_enemie, (sfVector2f) { 50, 120 });
    sfVector2f scale = {4, 4};
    sfSprite_setScale(fight->sp_info_enemie, scale);
    sfSprite_setTextureRect(fight->sp_info_enemie, \
    (sfIntRect) { 3, 3, 100, 29 });
    sfSprite_setTexture(fight->sp_info_player, fight->text_info_player, sfTrue);
    sfSprite_setPosition(fight->sp_info_player, (sfVector2f) { 614, 351 });
    sfSprite_setScale(fight->sp_info_player, scale);
    sfSprite_setTextureRect(fight->sp_info_player, \
    (sfIntRect) { 3, 45, 104, 37 });
}

void set_hp(fight_t *fight)
{
    sfVector2f size = {200, 20};
    fight->hp_ennemi = sfRectangleShape_create();
    fight->hp_player = sfRectangleShape_create();
    sfRectangleShape_setSize(fight->hp_ennemi, size);
    sfRectangleShape_setFillColor(fight->hp_ennemi, sfGreen);
    sfRectangleShape_setPosition(fight->hp_ennemi, (sfVector2f) { 202, 184 });
    sfRectangleShape_setSize(fight->hp_player, size);
    sfRectangleShape_setFillColor(fight->hp_player, sfGreen);
    sfRectangleShape_setPosition(fight->hp_player, (sfVector2f) { 802, 411 });
}

void set_xp(fight_t *fight)
{
    sfVector2f size = {0, 9};
    fight->xp_player = sfRectangleShape_create();
    sfRectangleShape_setSize(fight->xp_player, size);
    sfRectangleShape_setFillColor(fight->xp_player, sfBlue);
    sfRectangleShape_setPosition(fight->xp_player, (sfVector2f) { 742, 478 });
}