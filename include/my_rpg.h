/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** my_defender.h
*/

#ifndef _MY_RPG_H_
#define _MY_RPG_H_

#include "my.h"
#include "my_struct.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


            //INIT

//init_all_struct
all_t *init_all_struct(void);

//init_basics
sfRenderWindow *init_window(basics_t *basics);
basics_t *init_basics(void);

//init_button
button_t *init_button(int x, int y, int width, int height);

//init_game
game_t *init_game(void);
void set_bg(game_t *game);
void set_hero(game_t *game);
void set_map(game_t *game);

//init_how_to_play
htp_t *init_how_to_play(void);
void set_htpbg(htp_t *htp);
void set_htp_quit_btn(htp_t *htp);

//init_map
char *load_file_in_mem(char const *filepath);
int count_lines(char *str);
void my_str_to_wordtab(game_t *game, char *str);
int cols(char *str, int i);

//init_menu
menu_t *init_menu(void);
void set_menu_bg(menu_t *menu);
void set_play_btn(menu_t *menu);
void set_quit_btn(menu_t *menu);
void set_htp_btn(menu_t *menu);

//init_resume_menu
res_menu_t *init_resume_menu(void);
void set_res_menu_bg(res_menu_t *res_menu);
void set_resume_btn(res_menu_t *res_menu);
void set_menu_btn(res_menu_t *res_menu);
void set_quit_btn2(res_menu_t *res_menu);

//init_resume_menu2
void set_soundon_btn(res_menu_t *res_menu);
void set_soundoff_btn(res_menu_t *res_menu);

//init_dialogue
dialogue_t *init_bg(dialogue_t *all);
dialogue_t *init_text(dialogue_t *all, char *text);
dialogue_t *init_all_dialogue(void);

//init_fight
fight_t *set_text_fight(fight_t *fight);
sfText *set_info_text(sfText *text, sfVector2f pos, int size);
void set_info(fight_t *fight);
void set_hp(fight_t *fight);
void set_xp(fight_t *fight);

//init_fight2
void set_bg_fight(fight_t *fight);
void set_string(all_t *all);
fight_t *init_fight(void);
void set_box(fight_t *fight);

//init_inventory
inventory_t *init_inventory(void);
void set_inventory(inventory_t *inventory);
void init_inv_texture(inventory_t *inventory);

            //EVENTS

//analyse_event
bool is_mouse_on_btn(sfMouseMoveEvent event, button_t *button);
bool is_btn_clicked(sfMouseButtonEvent event, button_t *button);
void analyse_event(all_t *all);
void analyse_event2(all_t *all, sfEvent event);

//bag_event
void bag_event(all_t *all, sfEvent event);

//game_event
sfSprite *cpy_sprite(char *text, int pos);
attack_t **cpy_all_attack(attack_t **arr);
pokemon_t *init_pokemon(pokemon_t *pokemon_dest, pokemon_t *pokemon_src);
void game_event(all_t *all, sfEvent event);
int check_coll(all_t *all, sfEvent event);

//game_event2
void hero_mouv_event(all_t *all, sfEvent event);
void other_game_event(all_t *all, sfEvent event);

//hero_mouv_event
void hero_mouv_event(all_t *all, sfEvent event);
void update_hero(all_t *all, sfEvent event);
int check_coll(all_t *all, sfEvent event);
int check_emplacement(char emplacement);
void move_player(all_t *all, sfEvent event);

//menu_event
void menu_event(all_t *all, sfEvent event);
void analyse_mouse_event_menu(all_t *all, sfEvent event);
void btn_scale_menu_event(all_t *all, sfEvent event);

// resume_menu_event
void resume_menu_event(all_t *all, sfEvent event);
void analyse_mouse_event_resume_menu(all_t *all, sfEvent event);
void music_btn_event(all_t *all, sfEvent event);
void btn_scale_resume_menu_event(all_t *all, sfEvent event);

//htp_event
void htp_event(all_t *all, sfEvent event);
void analyse_mouse_event_htp(all_t *all, sfEvent event);

//pokecenter
void interact_with_joel(all_t *all, sfEvent event);
void dialogue_w_joel(all_t *all, sfEvent event);

//inventory_event
void inventory_event(all_t *all, sfEvent event);
void inventory_button_event(all_t *all, sfEvent event);

//teleport
void teleport_to_previous_pos(game_t *game);
void teleport_to_mart(game_t *game);
void teleport_to_pokedex(game_t *game);
void teleport_to_house(game_t *game);
void teleport_to_green_house(game_t *game);

//teleport_up_down
bool is_hero_at_teleport_up(int py, int px);
bool is_hero_at_teleport_down(int py, int px);
void teleport_up(game_t *game);
void teleport_down(game_t *game);

// is_in_front_of_npc
bool is_in_front_of_npc(game_t *game);

//check_imput_main
void check_imput_main(all_t *all, sfEvent event);
void check_imput_main2(all_t *all, sfEvent event);

//fight
sfText *init_text_fight(sfText *texte, char *text, sfColor color);
char *init_intro_fight(char *start, char *pokemon, char *end);
void set_wait(all_t *all);
void set_intro(all_t *all);
void destroy_wild(pokemon_t *destroy);

//fight2
char *get_type(type_t type);
void update_info(all_t *all);
void arrow_attack_box(all_t *all, sfEvent event);
void calc_xp(all_t *all);
void state_end_fight(all_t *all);

//fight3
void state_attack(all_t *all, sfEvent event);
void state_main(all_t *all);
void move_arrow(all_t *all, sfEvent event);
void state_intro(all_t *all);
void fight_event(all_t *all, sfEvent event);
void update_info_poke(all_t *all);
void set_text_fight2(fight_t *fight);

    //DRAW

//draw_bag
void draw_bag(all_t *all);

//draw_game
void draw_game(all_t *all);

//menu
void draw_menu(all_t *all);

//draw_resume_menu
void draw_resume_menu(all_t *all);

//draw_htp
void draw_htp(all_t *all);

//draw_fight
void draw_fight(all_t *all);
void draw_info_pokemon(all_t *all);
void draw_info_ennemie(all_t *all);
void draw_info_poke(all_t *all);

//update_hero
void move_rect(sfIntRect *rect, int offset, int max_value);
void move_up(all_t *all, int speed);
void move_down(all_t *all, int speed);
void move_left(all_t *all, int speed);
void move_right(all_t *all, int speed);

//draw_dialogue
void draw_dialogue(all_t *all);

//draw_inventory
void draw_inventory(all_t *all);

            //OTHER

//destroy
void destroy_all(all_t *all);
void destroy_menu(menu_t *menu);
void destroy_resume_menu(res_menu_t *res_menu);
void destroy_game(game_t *game);
void destroy_basics(basics_t *basics);

//destroy2
void destroy_htp(htp_t *htp);
void destroy_dialogue(dialogue_t *dialogue);
void destroy_fight(fight_t *fight);
void destroy_inventory(inventory_t *inventory);
void destroy_pokedex_index(pokemon_t *pokemon);

//loop
int loop(all_t *all);
void loop_continue(all_t *all);

//my_defender
int my_rpg(void);

//tools
sfVector2f init_vector(float width, float height);
char *my_strcpy(char *dest, char *src);
char *my_strcat(char *dest, char const *src);

void draw_fight(all_t *all);
void set_bg_fight(fight_t *fight);
fight_t *init_fight(void);
void set_box(fight_t *fight);
void fight_event(all_t *all, sfEvent event);
void set_arrow_box(fight_t *fight);
void set_playable_box(fight_t *fight);
void find_rdm_poke(all_t *all);
void set_player(fight_t *player);
void set_ennemie(fight_t *ennemie);

// tools2
char **my_str_to_wordtab_pokedex(char *str, char prefixe);
int get_size_wordtab(char *str, int actual, char prefixe);
int get_row(char *str, char prefixe);
int my_getnbr(char const *str);
char *my_itoa(int nb_score);
char **my_str_to_wordtab_pokedex(char *str, char prefixe);

// Pokemon
char *read_index(char *filepath);
char *find_line(char *buffer, int i);
int get_size(char *buffer, int i);
sfSprite *create_pokesprite(sfSprite *sprite, char *text, int pos);
pokemon_t *init_poke(pokemon_t *index, char **tmp_arr, attack_t **arr);
pokemon_t **init_type(pokemon_t **index);
void save_pokedex(char *buffer, pokemon_t **index, attack_t **arr);
pokemon_t **init_pokedex_index(attack_t **arr);
void draw_poke(pokemon_t **index);
void pos_arrow_left(all_t *all);
void pos_arrow_right(all_t *all);
void pos_arrow_leftdown(all_t *all);
void pos_arrow_rightdown(all_t *all);
void detect_arrow(sfEvent event, all_t *all);
void pos_left_right_arrow(all_t *all, sfEvent event);
void pos_up_down_arrow(all_t *all, sfEvent event);
void stat_attack_poke(pokemon_t *pokemon_dest, pokemon_t *pokemon_src);
void if_house_player(all_t *all, sfEvent event);
void if_labo(all_t *all, sfEvent event);
void if_arene(all_t *all, sfEvent event);
void if_move(all_t *all, sfEvent event);
void if_pokemon(all_t *all, sfEvent event);
int detect_text(all_t *all, int x, int y);
void first_attack(all_t *all);
void second_attack(all_t *all);
void third_attack(all_t *all);
void fourth_attack(all_t *all);
void stat_of_poke(pokemon_t *index, char **tmp_arr);

pokemon_t **init_curent_poke(void);

attack_t *cpy_attack(attack_t *src, attack_t *dest);

//anime_poke
void anim_poke(all_t *all);
void move_rect_poke(sfIntRect *rect, int offset, int max_value, all_t *all);

//attack
attack_t **init_attack_index(void);
void check_if_attack(all_t *all, sfEvent event);
void do_attack(all_t *all, attack_t *attack, pokemon_t *pokemon, pokemon_t *ennemie);
void print_end_fight(all_t *all);
void if_precise_event(all_t *all, sfEvent event);


//mewtwo
void init_mewtwo(all_t *all);
void if_mewtwo_endfight(all_t *all);
void dialogue_w_mewtwo(all_t *all, sfEvent event);
void interact_with_mewtwo(all_t *all, sfEvent event);
dialogue_t *init_textt(dialogue_t *dialogue, char *text);

#endif
