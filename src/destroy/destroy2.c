/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** destroy2.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void destroy_htp(htp_t *htp)
{
    sfTexture_destroy(htp->tex_quit);
    sfTexture_destroy(htp->tex_htpbg);
    sfSprite_destroy(htp->sp_quit);
    sfSprite_destroy(htp->sp_htpbg);
    free(htp->quit_btn);
    free(htp);
}

void destroy_dialogue(dialogue_t *dialogue)
{
    sfFont_destroy(dialogue->font);
    sfText_destroy(dialogue->text);
    sfRectangleShape_destroy(dialogue->rect);
    sfSprite_destroy(dialogue->sprite);
    sfTexture_destroy(dialogue->texture);
    free(dialogue);
}

void destroy_fight(fight_t *fight)
{
    sfSprite_destroy(fight->sp_bg_fight);
    sfTexture_destroy(fight->text_bg_fight);
    sfSprite_destroy(fight->sp_bg_box);
    sfTexture_destroy(fight->text_bg_box);
    sfSprite_destroy(fight->sp_info_enemie);
    sfTexture_destroy(fight->text_info_enemie);
    sfSprite_destroy(fight->sp_info_player);
    sfTexture_destroy(fight->text_info_player);
    free(fight);
}

void destroy_inventory(inventory_t *inventory)
{
    sfSprite_destroy(inventory->sp_inv[0]);
    sfTexture_destroy(inventory->tex_inv[0]);
    sfSprite_destroy(inventory->sp_inv[1]);
    sfTexture_destroy(inventory->tex_inv[1]);
    sfSprite_destroy(inventory->sp_inv[2]);
    sfTexture_destroy(inventory->tex_inv[2]);
    sfSprite_destroy(inventory->sp_inv[3]);
    sfTexture_destroy(inventory->tex_inv[3]);
    sfSprite_destroy(inventory->sp_inv[4]);
    sfTexture_destroy(inventory->tex_inv[4]);
    sfSprite_destroy(inventory->sp_inv[5]);
    sfTexture_destroy(inventory->tex_inv[5]);
    sfSprite_destroy(inventory->sp_inv[6]);
    sfTexture_destroy(inventory->tex_inv[6]);
    sfSprite_destroy(inventory->sp_bag1);
    sfTexture_destroy(inventory->tex_bag1);
    sfSprite_destroy(inventory->sp_bag2);
    sfTexture_destroy(inventory->tex_bag2);
    free(inventory);
}
