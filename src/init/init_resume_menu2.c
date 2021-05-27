/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** init_resume_menu2.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void set_soundon_btn(res_menu_t *res_menu)
{
    res_menu->tex_soundon = \
    sfTexture_createFromFile("assets/map/menu/music_on.png", NULL);
    res_menu->sp_soundon = sfSprite_create();
    sfSprite_setTexture(res_menu->sp_soundon, res_menu->tex_soundon, sfTrue);
    res_menu->sound_pos.x = 50;
    res_menu->sound_pos.y = 540;
}

void set_soundoff_btn(res_menu_t *res_menu)
{
    res_menu->tex_soundoff = \
    sfTexture_createFromFile("assets/map/menu/music_off.png", NULL);
    res_menu->sp_soundoff = sfSprite_create();
    sfSprite_setTexture(res_menu->sp_soundoff, res_menu->tex_soundoff, sfTrue);
    res_menu->sound_pos.x = 50;
    res_menu->sound_pos.y = 540;
}