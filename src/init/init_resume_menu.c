/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** init_resume_menu.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

res_menu_t *init_resume_menu(void)
{
    res_menu_t *res_menu = malloc(sizeof(*res_menu));

    if (!res_menu)
        return (NULL);
    res_menu->music_state = 1;
    set_res_menu_bg(res_menu);
    set_resume_btn(res_menu);
    set_menu_btn(res_menu);
    set_quit_btn2(res_menu);
    set_soundon_btn(res_menu);
    set_soundoff_btn(res_menu);
    res_menu->res_btn = init_button(335, 250, 420, 55);
    res_menu->menu_btn = init_button(335, 350, 420, 55);
    res_menu->quit_btn = init_button(335, 450, 420, 55);
    res_menu->sound_btn = init_button(50, 540, 124, 124);
    return (res_menu);
}

void set_res_menu_bg(res_menu_t *res_menu)
{
    res_menu->tex_resbg = \
    sfTexture_createFromFile("assets/map/menu/pause_bg.jpg", NULL);
    res_menu->sp_resbg = sfSprite_create();
    sfSprite_setTexture(res_menu->sp_resbg, res_menu->tex_resbg, sfTrue);
}

void set_resume_btn(res_menu_t *res_menu)
{
    res_menu->tex_res = \
    sfTexture_createFromFile("assets/map/menu/button_resume.png", NULL);
    res_menu->sp_res = sfSprite_create();
    sfSprite_setTexture(res_menu->sp_res, res_menu->tex_res, \
    sfTrue);
    res_menu->res_pos.x = 335;
    res_menu->res_pos.y = 250;
}

void set_menu_btn(res_menu_t *res_menu)
{
    res_menu->tex_menu = \
    sfTexture_createFromFile("assets/map/menu/button_menu.png", NULL);
    res_menu->sp_menu = sfSprite_create();
    sfSprite_setTexture(res_menu->sp_menu, res_menu->tex_menu, sfTrue);
    res_menu->menu_pos.x = 335;
    res_menu->menu_pos.y = 350;

}

void set_quit_btn2(res_menu_t *res_menu)
{
    res_menu->tex_quit = \
    sfTexture_createFromFile("assets/map/menu/button_quit.png", NULL);
    res_menu->sp_quit = sfSprite_create();
    sfSprite_setTexture(res_menu->sp_quit, res_menu->tex_quit, sfTrue);
    res_menu->quit_pos.x = 335;
    res_menu->quit_pos.y = 450;

}