/*
** EPITECH PROJECT, 2021
** init_attack.c
** File description:
** init_attack
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

attack_t *init_attack(attack_t *index, char **tmp_arr)
{
    index->name = malloc(sizeof(char) * (my_strlen(tmp_arr[0]) + 2));
    index->name = my_strcpy(index->name, tmp_arr[0]);
    index->type = my_getnbr(tmp_arr[1]);
    index->pp_max = my_getnbr(tmp_arr[2]);
    index->pp_actual = index->pp_max;
    index->dmg = my_getnbr(tmp_arr[3]);
    index->stat = malloc(sizeof(int) * 3);
    index->stat[HP] = my_getnbr(tmp_arr[4]);
    index->stat[ATK] = my_getnbr(tmp_arr[5]);
    index->stat[SPEED] = my_getnbr(tmp_arr[6]);
    return (index);
}

void save_attack(char *buffer, attack_t **index)
{
    int i = 0;
    char *tmp = 0;
    char **tmp_arr = NULL;
    int j = 0;
    while (index[j] != NULL) {
        tmp = find_line(buffer, i);
        i += my_strlen(tmp);
        tmp_arr = my_str_to_wordtab_pokedex(tmp, ';');
        index[j] = init_attack(index[j], tmp_arr);
        j++;
    }
}

attack_t **init_attack_index(void)
{
    char *buffer = read_index("assets/fight/attack");
    attack_t **index = malloc(sizeof(*index) * 26);
    for (int i = 0; i < 25; i++)
        index[i] = malloc(sizeof(**index));
    index[25] = NULL;
    save_attack(buffer, index);
    free(buffer);
    return (index);
}