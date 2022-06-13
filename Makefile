NAME = fdf

SRC =	fdf.c read_file.c utils.c ft_split.c get_next_line.c get_next_line_utils.c

OBJ = $(patsubst %.c, %.o, $(SRC))

MLX = ./minilibx_macos/

HEADER = fdf.h

FLAGS	= -Wall -Wextra -Werror #-I

.PHONY : all clean fclean re

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@
# -Imlx 

all : $(NAME)
	@echo "\033[32m\033[40m\033[1m[FDF Compiled]"

# mlx : 
# 	make -C $(MLX)

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
