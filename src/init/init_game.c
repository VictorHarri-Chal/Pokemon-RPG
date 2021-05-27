/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** init_game.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(*game));

    if (!game)
        return (NULL);
    game->emplacement = OUTSIDE;
    set_bg(game);
    set_map(game);
    set_hero(game);
    return (game);
}

void set_bg(game_t *game)
{
    game->map_pos.x = -5835;
    game->map_pos.y = -7520;
    game->tex_gamebg = \
    sfTexture_createFromFile("assets/map/game/map_hoenn_ende.jpg", NULL);
    game->sp_gamebg = sfSprite_create();
    sfSprite_setTexture(game->sp_gamebg, game->tex_gamebg, sfTrue);
    sfVector2f scale = {3.0, 3.0};
    sfSprite_setScale(game->sp_gamebg, scale);
}

void set_hero(game_t *game)
{
    game->hero_pos.x = 540;
    game->hero_pos.y = 360;
    game->hero_pos_text.y = 2643;
    game->hero_pos_text.x = 2138;
    game->rect_hero.width = 67;
    game->rect_hero.height = 69.5;
    game->rect_hero.left = 0;
    game->rect_hero.top = 0;
    game->tex_hero = sfTexture_createFromFile(\
    "assets/characters/hero.png", NULL);
    game->sp_hero = sfSprite_create();
    sfSprite_setTexture(game->sp_hero, game->tex_hero, sfTrue);
    game->state = 0;
}

void set_map(game_t *game)
{
    char *map_file = load_file_in_mem("assets/map/game/log");

    my_str_to_wordtab(game, map_file);
    free(map_file);
}
