##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	=	pbrain-gomoku-ai

SRCS	=	main.cpp	\
			IA.cpp	\
		process.cpp

SRCDIR	=	./src/

OBJS	=	$(addprefix $(SRCDIR), $(SRCS:.c=.o))

CFLAGS	+=	-I./include -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJS)
			g++ -g3 -o $(NAME) $(OBJS) $(CFLAGS)

clean:
			rm -f src/*.o
			rm -f *.o

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
