/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** init_inventory.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(*inventory));
    if (!inventory)
        return (NULL);
    inventory->inventory_state = 0;
    inventory->bag_state = 0;
    set_inventory(inventory);
    return (inventory);
}

void set_inventory(inventory_t *inventory)
{
    inventory->tex_inv = malloc(sizeof(sfTexture *) * 7);
    inventory->sp_inv = malloc(sizeof(sfSprite *) * 7);
    if (!inventory->tex_inv || !inventory->sp_inv)
        return ;
    for (int i = 0; i < 7; i++)
        inventory->sp_inv[i] = sfSprite_create();
    inventory->sp_bag1 = sfSprite_create();
    inventory->sp_bag2 = sfSprite_create();
    init_inv_texture(inventory);
    for (int j = 0; j < 7; j++)
        sfSprite_setTexture(inventory->sp_inv[j], inventory->tex_inv[j], \
        sfTrue);
    sfSprite_setTexture(inventory->sp_bag1, inventory->tex_bag1, sfTrue);
    sfSprite_setTexture(inventory->sp_bag2, inventory->tex_bag2, sfTrue);
}

void init_inv_texture(inventory_t *inventory)
{
    inventory->tex_inv[0] = \
    sfTexture_createFromFile("assets/inventory/pokédex_inv.png", NULL);
    inventory->tex_inv[1] = \
    sfTexture_createFromFile("assets/inventory/pokemon_inv.png", NULL);
    inventory->tex_inv[2] = \
    sfTexture_createFromFile("assets/inventory/bag_inv.png", NULL);
    inventory->tex_inv[3] = \
    sfTexture_createFromFile("assets/inventory/profil_inv.png", NULL);
    inventory->tex_inv[4] = \
    sfTexture_createFromFile("assets/inventory/save_inv.png", NULL);
    inventory->tex_inv[5] = \
    sfTexture_createFromFile("assets/inventory/options_inv.png", NULL);
    inventory->tex_inv[6] = \
    sfTexture_createFromFile("assets/inventory/quit_inv.png", NULL);
    inventory->tex_bag1 = \
    sfTexture_createFromFile("assets/inventory/bag/bag1.png", NULL);
    inventory->tex_bag2 = \
    sfTexture_createFromFile("assets/inventory/bag/bag2.png", NULL);
}