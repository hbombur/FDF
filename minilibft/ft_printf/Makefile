NAME = libftprintf.a

SRC =	ft_printf.c ft_printf_utils.c

OBJ = $(patsubst %.c, %.o, $(SRC))

HEADER = ft_printf.h

FLAGS	= -Wall -Wextra -Werror -I

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) $(HEADER) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re