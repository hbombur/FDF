NAME = fdf

SRC = fdf.c get_next_line.c get_next_line_utils.c read_file.c \
		ft_split.c ft_utils.c key_hook.c draw.c menu.c init_win.c \
		img_utils.c

OBJ = $(patsubst %.c, %.o, $(SRC))

SRC_BONUS = fdf.c get_next_line.c get_next_line_utils.c read_file.c \
			ft_split.c ft_utils.c key_hook.c draw.c menu.c init_win.c

OBJ_BONUS = $(patsubst %.c, %.o, $(SRC_BONUS))

FLAGS	= -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

MATH_FLAGS = -lm

MLX = ./minilibx_macos/

HEADER = fdf.h



.PHONY : all clean fclean re

%.o : %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)
	@echo "\033[32;40;1m[FDF Compiled]"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MATH_FLAGS) $(MLX_FLAGS) -o $(NAME)

bonus : $(OBJ_BONUS)
	$(CC) $(CC_FLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ_BONUS) -o $(NAME)

clean :
	@rm -f $(OBJ)
	@echo "\033[31;40;1m[clean object file...]"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[31;40;1m[clean all...]"

re : fclean all
	@echo "\033[33;1m[The program has been recompiled...]"
	
