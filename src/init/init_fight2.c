/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** init_fight2.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

fight_t *init_fight(void)
{
    fight_t *fight = malloc(sizeof(*fight));
    if (!fight)
        return (NULL);
    set_bg_fight(fight);
    set_box(fight);
    set_info(fight);
    set_hp(fight);
    set_xp(fight);
    fight = set_text_fight(fight);
    fight->state = NO_FIGHT;
    fight->pos_arrow.x = 580;
    fight->pos_arrow.y = 550;
    sfText_setString(fight->texte_slash, "/");
    return (fight);
}

void set_box(fight_t *fight)
{
    fight->text_bg_box = \
    sfTexture_createFromFile("assets/fight/asset_fight.png", NULL);
    fight->sp_bg_box = sfSprite_create();
    sfSprite_setTexture(fight->sp_bg_box, fight->text_bg_box, sfTrue);
    sfSprite_setPosition(fight->sp_bg_box, (sfVector2f) { 0, 500 });
    sfVector2f scale = {4.52, 4.69};
    sfSprite_setScale(fight->sp_bg_box, scale);
    sfSprite_setTextureRect(fight->sp_bg_box, (sfIntRect) { 298, 57, 239, 47 });
}

void set_bg_fight(fight_t *fight)
{
    fight->text_bg_fight = \
    sfTexture_createFromFile("assets/fight/pos_pokemon.png", NULL);
    fight->sp_bg_fight = sfSprite_create();
    sfSprite_setTexture(fight->sp_bg_fight, fight->text_bg_fight, sfTrue);
    sfVector2f scale = {4.5, 4.5};
    sfSprite_setScale(fight->sp_bg_fight, scale);
}

void set_text_fight2(fight_t *fight)
{
    fight->texte_slash = \
    set_info_text(fight->texte_slash, (sfVector2f) { 925, 430 }, 40);
    fight->texte_atk1 = \
    set_info_text(fight->texte_atk1, (sfVector2f) { 70, 520 }, 60);
    fight->texte_atk2 = \
    set_info_text(fight->texte_atk2, (sfVector2f) { 400, 520 }, 60);
    fight->texte_atk3 = \
    set_info_text(fight->texte_atk3, (sfVector2f) { 70, 610 }, 60);
    fight->texte_atk4 = \
    set_info_text(fight->texte_atk4, (sfVector2f) { 400, 610 }, 60);
    fight->texte_ppactual = \
    set_info_text(fight->texte_ppactual, (sfVector2f) { 905, 530 }, 60);
    fight->texte_ppmax = \
    set_info_text(fight->texte_ppmax, (sfVector2f) { 995, 530 }, 60);
    fight->texte_type = \
    set_info_text(fight->texte_type, (sfVector2f) { 865, 610 }, 60);
}