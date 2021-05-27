/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** destroy.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void destroy_all(all_t *all)
{
    destroy_inventory(all->inventory);
    destroy_fight(all->fight);
    if (all->dialogue)
        destroy_dialogue(all->dialogue);
    destroy_htp(all->htp);
    destroy_menu(all->menu);
    destroy_resume_menu(all->res_menu);
    destroy_game(all->game);
    destroy_basics(all->basics);
    free(all);
}

void destroy_menu(menu_t *menu)
{
    sfTexture_destroy(menu->tex_quit);
    sfTexture_destroy(menu->tex_htp);
    sfTexture_destroy(menu->tex_play);
    sfTexture_destroy(menu->tex_menubg);
    sfSprite_destroy(menu->sp_quit);
    sfSprite_destroy(menu->sp_htp);
    sfSprite_destroy(menu->sp_play);
    sfSprite_destroy(menu->sp_menubg);
    free(menu->play_btn);
    free(menu->htp_btn);
    free(menu->quit_btn);
    free(menu);
}

void destroy_resume_menu(res_menu_t *res_menu)
{
    sfTexture_destroy(res_menu->tex_soundon);
    sfTexture_destroy(res_menu->tex_soundoff);
    sfTexture_destroy(res_menu->tex_quit);
    sfTexture_destroy(res_menu->tex_menu);
    sfTexture_destroy(res_menu->tex_res);
    sfTexture_destroy(res_menu->tex_resbg);
    sfSprite_destroy(res_menu->sp_soundon);
    sfSprite_destroy(res_menu->sp_soundoff);
    sfSprite_destroy(res_menu->sp_quit);
    sfSprite_destroy(res_menu->sp_menu);
    sfSprite_destroy(res_menu->sp_res);
    sfSprite_destroy(res_menu->sp_resbg);
    free(res_menu->sound_btn);
    free(res_menu->res_btn);
    free(res_menu->menu_btn);
    free(res_menu->quit_btn);
    free(res_menu);
}

void destroy_game(game_t *game)
{
    sfTexture_destroy(game->tex_gamebg);
    sfSprite_destroy(game->sp_gamebg);
    sfTexture_destroy(game->tex_hero);
    sfSprite_destroy(game->sp_hero);
    free(game->map);
    free(game);
}

void destroy_basics(basics_t *basics)
{
    sfRenderWindow_destroy(basics->window);
    sfMusic_destroy(basics->music);
    free(basics);
}
