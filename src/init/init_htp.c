/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** init_htp.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

htp_t *init_how_to_play(void)
{
    htp_t *htp = malloc(sizeof(*htp));

    if (!htp)
        return (NULL);
    set_htpbg(htp);
    set_htp_quit_btn(htp);
    htp->quit_btn = init_button(950, 20, 100, 100);
    return (htp);
}

void set_htpbg(htp_t *htp)
{
    htp->tex_htpbg = sfTexture_createFromFile("assets/map/htp/htp.png" \
    , NULL);
    htp->sp_htpbg = sfSprite_create();
    sfSprite_setTexture(htp->sp_htpbg, htp->tex_htpbg, sfTrue);
}

void set_htp_quit_btn(htp_t *htp)
{
    htp->tex_quit = sfTexture_createFromFile("assets/map/htp/button_quit.png" \
    , NULL);
    htp->sp_quit = sfSprite_create();
    sfSprite_setTexture(htp->sp_quit, htp->tex_quit, sfTrue);
    htp->quit_pos.x = 950;
    htp->quit_pos.y = 20;
}
