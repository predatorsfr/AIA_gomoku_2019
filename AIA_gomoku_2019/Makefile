##
## EPITECH PROJECT, 2019
## 301dannon_2019
## File description:
## Makefile
##

NAME	=	pbrain-gomoku-ai

SRCS	=	main.cpp	\
			process.cpp	\
			IA.cpp

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
