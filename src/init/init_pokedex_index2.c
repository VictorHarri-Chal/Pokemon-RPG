/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** init_pokedex_index2.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

attack_t **init_att(char **tmp_arr, attack_t **arr)
{
    int j = 5;
    int u = 0;
    int y = 0;
    attack_t **all_attack = malloc(sizeof(*all_attack) * 6);
    for (int i = 0; i < 4; i++)
        all_attack[i] = malloc(sizeof(**all_attack));
    all_attack[5] = NULL;
    while (j < 9) {
        while (my_strcmp(tmp_arr[j], arr[u]->name) != 0)
            u++;
        all_attack[y] = cpy_attack(arr[u], all_attack[y]);
        j++;
        y++;
        u = 0;
    }
    return (all_attack);
}

pokemon_t *init_poke(pokemon_t *index, char **tmp_arr, attack_t **arr)
{
    index->rect_poke = (sfIntRect) {0, 0, 96, 96};
    index->name = malloc(sizeof(char) * (my_strlen(tmp_arr[0]) + 1));
    index->name = my_strcpy(index->name, tmp_arr[0]);
    index->text_back = malloc(sizeof(char) * (my_strlen(tmp_arr[10]) + 1));
    index->text_back = my_strcpy(index->text_back, tmp_arr[10]);
    index->text_front = malloc(sizeof(char) * (my_strlen(tmp_arr[9]) + 1));
    index->text_front = my_strcpy(index->text_front, tmp_arr[9]);
    index->type = my_getnbr(tmp_arr[1]);
    index->stat = malloc(sizeof(int) * 3);
    stat_of_poke(index, tmp_arr);
    index->sp_front = create_pokesprite(index->sp_front, index->text_back, 1);
    index->sp_back = create_pokesprite(index->sp_back, index->text_back, 0);
    index->hp_actual = index->stat[0];
    index->level = 0;
    index->xp = 0;
    index->rect_max = my_getnbr(tmp_arr[11]);
    index->anim_poke = 0;
    index->all_atk = init_att(tmp_arr, arr);
    return (index);
}

void save_pokedex(char *buffer, pokemon_t **index, attack_t **arr)
{
    int i = 0;
    char *tmp = 0;
    char **tmp_arr;
    int j = 0;
    while (index[j] != NULL) {
        tmp = find_line(buffer, i);
        i += my_strlen(tmp);
        tmp_arr = my_str_to_wordtab_pokedex(tmp, ';');
        index[j] = init_poke(index[j], tmp_arr, arr);
        j++;
    }
}

void draw_poke(pokemon_t **index)
{
    int j = 0;
    while (index[j] != NULL)
    {
        write(1, index[j]->name, my_strlen(index[j]->name));
        my_putchar('\n');
        my_put_nbr(index[j]->hp_actual);
        my_putchar('\n');
        my_put_nbr(index[j]->stat[HP]);
        my_putchar('\n');
        my_put_nbr(index[j]->stat[ATK]);
        my_putchar('\n');
        my_put_nbr(index[j]->stat[SPEED]);
        my_putchar('\n');
        j++;
    }
}

pokemon_t **init_pokedex_index(attack_t **arr)
{
    char *buffer = read_index("assets/fight/pokedex");
    pokemon_t **index = malloc(sizeof(*index) * 12);
    for (int i = 0; i < 11; i++)
        index[i] = malloc(sizeof(**index));
    index[11] = NULL;
    save_pokedex(buffer, index, arr);
    free(buffer);
    return (index);
}