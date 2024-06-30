NAME = libftprintf.a
CC = cc
AR = ar rcs
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
OPTION = -c
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $(OBJ)

$(OBJ):
	$(CC) $(FLAGS) $(OPTION) $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
