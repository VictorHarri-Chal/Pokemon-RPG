##
## EPITECH PROJECT, 2020
## B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
## File description:
## Makefile
##

SRC 		=	src/main.c 						\
				src/my_rpg.c 					\
				src/init/init_all_struct.c 		\
				src/init/init_basics.c 			\
				src/init/init_menu.c 			\
				src/init/init_resume_menu.c 	\
				src/init/init_resume_menu2.c 	\
				src/init/init_game.c 			\
				src/init/init_htp.c 			\
				src/init/init_map.c 			\
				src/init/init_button.c 			\
				src/init/init_dialogue.c 		\
				src/init/init_inventory.c 		\
				src/init/init_fight.c			\
				src/init/init_fight2.c 			\
				src/init/init_pokedex_index.c	\
				src/init/init_pokedex_index2.c 	\
				src/init/init_curent_poke.c		\
				src/init/init_attack.c			\
				src/events/analyse_event.c 		\
				src/events/menu_event.c 		\
				src/events/resume_menu_event.c 	\
				src/events/game_event.c 		\
				src/events/game_event2.c 		\
				src/events/htp_event.c 			\
				src/events/pokecenter.c			\
				src/events/inventory_event.c 	\
				src/events/teleport.c 			\
				src/events/teleport_up_down.c 	\
				src/events/bag_event.c 			\
				src/events/if_attack.c			\
				src/events/mewtwo.c 			\
				src/events/rdm_poke.c			\
				src/events/anim_poke.c			\
				src/events/fight.c				\
				src/events/fight2.c				\
				src/events/fight3.c 			\
				src/events/create_fight.c		\
				src/events/check_imput_main.c	\
				src/loop.c 						\
				src/draw/draw_menu.c 			\
				src/draw/draw_resume_menu.c 	\
				src/draw/draw_game.c 			\
				src/draw/draw_htp.c 			\
				src/draw/update_hero.c 			\
				src/draw/draw_dialogue.c		\
				src/draw/draw_fight.c 			\
				src/draw/draw_inventory.c 		\
				src/draw/draw_bag.c 			\
				src/destroy/destroy.c 			\
				src/destroy/destroy2.c 			\
				src/utils.c 					\
				src/tools.c 					\
				src/tools2.c					\
				src/draw/draw_info.c			\
				src/events/fight_event.c		\
				src/events/move_arrow_attack.c	\
				src/events/stat_poke.c			\
				src/events/if_teleportation.c	\
				src/events/detection_text.c		\
				src/events/fight_poke.c			\
				src/init/stat_of_poke.c			\
				src/events/if_mewtwo.c

NAME	=	my_rpg

CC = gcc

CFLAGS	+=	-Wall -Wextra -Werror -Wshadow -I./include/

SFML 	= -lcsfml-graphics -lcsfml-system -lcsfml-audio

OBJ	=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(SFML)
				rm -f $(OBJ)

clean:
				rm -f $(OBJ)

fclean:	clean
				rm -f $(NAME)

re:			fclean all

dbg:		CFLAGS += -g
dbg: re

.PHONY:	all	clean	fclean	re	dbg
