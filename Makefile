NAME = fdf

SRC =	fdf.c

OBJ = $(patsubst %.c, %.o, $(SRC))

FTPRINTF = ./minilibft/ft_printf/libftprintf.a

HEADER = fdf.h

FLAGS	= -Wall -Wextra -Werror -I

.PHONY : all clean fclean re

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) $(HEADER) -c $< -o $@

all : ft_printf $(NAME)
	@echo "\033[32m\033[40m\033[1m[FDF Compiled]"

ft_printf :
	make -C ft_printf

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $(FTPRINTF) $(OBJ)$?

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
