##
## Makefile for  in /home/thomas/Documents/epitech/gfx_tekpaint
##
## Made by Thomas HENON
## Login   <thomas.henon@epitech.net>
##
## Started on  Mon Jan 18 15:41:52 2016 Thomas HENON
## Last update Tue Jan 26 22:01:16 2016 Thomas HENON
##

CC		=	gcc

NAME		=	tekpaint

LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
				-L/usr/local/lib \
				-lsfml-audio \
				-lsfml-graphics \
				-lsfml-window \
				-lsfml-system \
				-lstdc++ -ldl \
				-lm

#FLAG		=	-W -Wall -ansi -pedantic -I/home/${USER}/.froot/include/ -I includes/ -g -Wunused-parameter
FLAG		= -I/home/${USER}/.froot/include/ -I includes/

SRC		=	srcs/main.c \
				srcs/palette.c \
				srcs/init.c \
				srcs/init2.c \
				srcs/my.c \
				srcs/tkp.c \
				srcs/bases.c \
				srcs/bases2.c \
				srcs/bmp.c \
				srcs/bmp2.c \
				srcs/linked_lists.c \
				srcs/buttons.c \
				srcs/buttons_event.c \
				srcs/buttons_event2.c \
				srcs/buttons_event3.c \
				srcs/events.c \
				srcs/tools/line.c \
				srcs/tools/pen.c \
				srcs/tools/circle.c \
				srcs/tools/square.c \
				srcs/tools/square2.c \
				srcs/tools/empty_square.c \
				srcs/tools/eraser.c \
				srcs/buttons/buttons_pen.c \
				srcs/buttons/icon_tool.c \
				srcs/buttons/buttons_circle.c \
				srcs/buttons/buttons_empty_circle.c \
				srcs/buttons/buttons_empty_square.c \
				srcs/buttons/buttons_square.c \
				srcs/buttons/buttons_line.c \
				srcs/buttons/buttons_more.c \
				srcs/buttons/buttons_less.c \
				srcs/buttons/buttons_bucket.c \
				srcs/buttons/buttons_clean.c \
				srcs/buttons/buttons_empty.c \
				srcs/buttons/buttons_palette.c \
				srcs/buttons/buttons_save.c \
				srcs/buttons/buttons_load.c \
				srcs/buttons/buttons_erase.c \
				srcs/buttons/buttons_color.c \
				srcs/buttons/buttons_save_bmp.c \
				srcs/buttons/buttons_load_bmp.c \
				srcs/util.c \
				srcs/font.c \
				srcs/explorer.c \
				srcs/explorer2.c

OBJ		=	$(SRC:.c=.o)

$(NAME): $(OBJ)
		$(CC) $(OBJ) $(LIB) -o $(NAME)

all:		$(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
re:		fclean all

.c.o:
		$(CC) -c $< -o $@ $(FLAG)

.PHONY: all clean fclean re
