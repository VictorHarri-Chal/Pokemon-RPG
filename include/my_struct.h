/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** my_struct.h
*/

#ifndef _MY_STRUCT_H_
#define _MY_STRUCT_H_

#include "my.h"
#include "my_rpg.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define  HP 0
#define  ATK 1
#define  SPEED 2


typedef enum type
{
    FIRE,
    WATER,
    GRASS,
    NORMAL,
    ROCK,
    PSY,
    GROUND
} type_t;

typedef enum fight_state
{
    MAIN,
    MAIN_WAIT,
    BAG,
    POKEMON,
    ESCAPE,
    END_FIGHT,
    ATACK,
    NO_FIGHT,
    INTRO,
    OUTRO,
    OUTRO_WAIT
} fight_state_t;

typedef enum scene
{
    MENU,
    RESUME_MENU,
    GAME,
    END,
    HTP,
    FIGHT,
    INVENTORY,
    INV_BAG
} scene_t;

typedef enum emplacement
{
    OUTSIDE,
    POKEDEX,
    MART,
    BUSH,
    PREVIOUS,
    HOUSE,
    GREEN_HOUSE
} emplacement_t;

typedef struct button
{
    sfRectangleShape *rect;
    sfVector2f *position;
    sfVector2f *size;
} button_t;

typedef struct basics
{
    sfRenderWindow *window;
    sfMusic *music;
    sfClock *clock;

} basics_t;

typedef struct menu
{
    sfTexture *tex_menubg;
    sfSprite *sp_menubg;
    sfTexture *tex_play;
    sfSprite *sp_play;
    sfVector2f play_pos;
    sfTexture *tex_htp;
    sfSprite *sp_htp;
    sfVector2f htp_pos;
    sfTexture *tex_quit;
    sfSprite *sp_quit;
    sfVector2f quit_pos;
    button_t *play_btn;
    button_t *htp_btn;
    button_t *quit_btn;
} menu_t;

typedef struct htp
{
    sfTexture *tex_htpbg;
    sfSprite *sp_htpbg;
    sfTexture *tex_quit;
    sfSprite *sp_quit;
    sfVector2f quit_pos;
    button_t *quit_btn;
} htp_t;

typedef struct game
{
    emplacement_t emplacement;
    sfTexture *tex_gamebg;
    sfSprite *sp_gamebg;
    sfVector2f map_pos;
    sfTexture *tex_hero;
    sfSprite *sp_hero;
    sfVector2f hero_pos;
    sfVector2i hero_pos_text;
    sfVector2i old_hero_pos_text;
    sfVector2f old_map_pos;
    sfIntRect rect_hero;
    char **map;
    int state;
} game_t;

typedef struct res_menu
{
    sfTexture *tex_resbg;
    sfSprite *sp_resbg;
    sfTexture *tex_res;
    sfSprite *sp_res;
    sfVector2f res_pos;
    sfTexture *tex_menu;
    sfSprite *sp_menu;
    sfVector2f menu_pos;
    sfTexture *tex_quit;
    sfSprite *sp_quit;
    sfVector2f quit_pos;
    sfTexture *tex_soundon;
    sfSprite *sp_soundon;
    sfTexture *tex_soundoff;
    sfSprite *sp_soundoff;
    sfVector2f sound_pos;
    int music_state;
    button_t *res_btn;
    button_t *menu_btn;
    button_t *quit_btn;
    button_t *sound_btn;
} res_menu_t;

typedef struct dialogue {
    sfSprite *sprite;
    sfTexture *texture;
    sfText *text;
    sfText *text2;
    sfFont *font;
    sfVector2f text_pos;
    sfVector2f size;
    sfVector2f pos;
    int state;
    sfRectangleShape *rect;
    char *filepath;
} dialogue_t;

typedef struct fight {
    sfSprite *sp_bg_fight;
    sfTexture *text_bg_fight;
    sfSprite *sp_bg_box;
    sfTexture *text_bg_box;
    sfSprite *sp_info_enemie;
    sfTexture *text_info_enemie;
    sfSprite *sp_info_player;
    sfTexture *text_info_player;
    sfSprite *sp_playable_box;
    sfTexture *text_playable_box;
    sfSprite *sp_arrow_box;
    sfTexture *text_arrow_box;
    fight_state_t state;
    sfText *text;
    sfFont *font;
    sfVector2f pos_arrow;
    sfText *texte_level_enemie;
    sfText *texte_level_player;
    sfText *texte_name_enemie;
    sfText *texte_name_player;
    sfText *texte_hp_max;
    sfText *texte_hp_actual;
    sfText *texte_slash;
    sfRectangleShape *hp_ennemi;
    sfRectangleShape *hp_player;
    sfRectangleShape *xp_player;
    sfText *wait;
    sfText *texte_ppactual;
    sfText *texte_ppmax;
    sfText *texte_type;
    sfText *texte_atk1;
    sfText *texte_atk2;
    sfText *texte_atk3;
    sfText *texte_atk4;
} fight_t;

typedef struct inventory {
    sfSprite **sp_inv;
    sfTexture **tex_inv;
    sfSprite *sp_bag1;
    sfTexture *tex_bag1;
    sfSprite *sp_bag2;
    sfTexture *tex_bag2;
    int inventory_state;
    int bag_state;
} inventory_t;

typedef struct attack {
    char *name;
    int pp_actual;
    int pp_max;
    type_t type;
    int dmg;
    int *stat;
} attack_t;


typedef struct pokemon
{
    char *name;
    sfSprite *sp_back;
    char *text_back;
    sfSprite *sp_front;
    char *text_front;
    type_t type;
    int *stat;
    int hp_actual;
    int level;
    float xp;
    int rect_max;
    sfIntRect rect_poke;
    int anim_poke;
    attack_t **all_atk;
} pokemon_t;

typedef struct all {
    scene_t scene;
    basics_t *basics;
    menu_t *menu;
    res_menu_t *res_menu;
    game_t *game;
    htp_t *htp;
    dialogue_t *dialogue;
    fight_t *fight;
    inventory_t *inventory;
    pokemon_t **pokedex_index;
    attack_t **attack_index;
    pokemon_t **current_poke;
    int nb_poke;
} all_t ;

#endif
