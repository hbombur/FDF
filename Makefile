# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 17:21:57 by hbombur           #+#    #+#              #
#    Updated: 2022/06/29 21:33:11 by hbombur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c get_next_line.c get_next_line_utils.c read_file.c \
		ft_split.c ft_utils.c key_hook.c draw.c menu.c init_win.c \
		img_utils.c

OBJ = $(patsubst %.c, %.o, $(SRC))

SRC_BONUS = fdf.c get_next_line.c get_next_line_utils.c read_file.c \
			ft_split.c ft_utils.c key_hook.c draw.c menu.c init_win.c \
			img_utils.c

OBJ_BONUS = $(patsubst %.c, %.o, $(SRC_BONUS))

FLAGS	= -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

MATH_FLAGS = -lm

HEADER = fdf.h



.PHONY : all clean fclean re


all : $(NAME)
	@echo "\033[32;49;1m[Program "FDF" Compiled]"

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ) -o $@

%.o : %.c $(HEADER)
	@echo "\033[36;49;1m" 
	$(CC) $(FLAGS) -c $< -o $@
	
bonus : $(OBJ_BONUS) 
	$(CC) $(FLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ_BONUS)  -o $(NAME)

clean :
	@echo "\033[33;49;1m[Remove object file...]"
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	@echo "\033[31;49;1m[Remove executable file...]"
	rm -rf $(NAME)

re : fclean $(NAME)
	@echo "\033[32;49;1m[The program has been recompiled]"
