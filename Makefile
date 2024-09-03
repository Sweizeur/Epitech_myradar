##
## EPITECH PROJECT, 2023
## makefile
## File description:
## 10
##

SRC	=	./main.c	\
		./fonctions/events.c	\
		./fonctions/fonctions.c	\
		./fonctions/moveplane.c	\
		./fonctions/check_collision.c	\
		./fonctions/parcing.c	\
		./fonctions/clock.c	\
		./fonctions/draw.c	\
		./fonctions/init_all.c	\
		./init.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_radar

CFLAGS	=	-W -Wall -Wextra

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

LDFLAGS	=	-L./lib/my -lmy -lm

all:	$(NAME) fclean

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CSFML)

clean:
	rm -f $(OBJ)
	find . -name '#*#' -delete -o -name '*~' -delete
	find . -name "coding-style-reports.log" -delete
	find . -name "vgcore*" -delete

fclean: clean

re: fclean all

.PHONY:	clean all fclean re
