##
## EPITECH PROJECT, 2019
## project_2019
## File description:
## Project makefile
##

DSRC	=	./src/

SRC	=	$(DSRC)main.cpp		\
		$(DSRC)arguments.cpp \

OBJ	=	$(SRC:.cpp=.o)

NAME	=	104intersection

CPPFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ)

clean:
	rm -f  $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY :        clean fclean re
