/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** analyse_event.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

bool is_mouse_on_btn(sfMouseMoveEvent event, button_t *button)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f rect_size = sfRectangleShape_getSize(button->rect);

    if ((event.x >= rect_pos.x && event.x <= rect_pos.x+rect_size.x) &&
    event.y >= rect_pos.y && event.y <= rect_pos.y+rect_size.y) {
        return (true);
    }
    return (false);
}

bool is_btn_clicked(sfMouseButtonEvent event, button_t *button)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f rect_size = sfRectangleShape_getSize(button->rect);

    if ((event.x >= rect_pos.x && event.x <= rect_pos.x+rect_size.x) &&
    event.y >= rect_pos.y && event.y <= rect_pos.y+rect_size.y) {
        return (true);
    }
    return (false);
}

void analyse_event(all_t *all)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(all->basics->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(all->basics->window);
            all->scene = END;
        }
        if (all->scene == GAME)
            game_event(all, event);
        if (all->scene == MENU)
            menu_event(all, event);
        if (all->scene == HTP)
            htp_event(all, event);
        if (all->scene == RESUME_MENU)
            resume_menu_event(all, event);
        analyse_event2(all, event);
    }
}

void analyse_event2(all_t *all, sfEvent event)
{
    if (all->scene == FIGHT)
            fight_event(all, event);
    if (all->scene == INVENTORY)
            inventory_event(all, event);
    if (all->scene == INV_BAG)
            bag_event(all, event);
}
