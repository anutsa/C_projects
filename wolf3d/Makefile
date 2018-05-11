# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anutsa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/22 16:55:08 by anutsa            #+#    #+#              #
#    Updated: 2017/10/22 16:56:56 by anutsa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CC = gcc
FLAGS = -Wall -Wextra -Werror -g

WLF_SRC_FLD = src/
WLF_OBJ_FLD = obj/
WLF_INC_FLD = includes/

WLF_SRC = main.c map.c draw.c keys.c move.c compute.c
WLF_OBJ = $(addprefix $(WLF_OBJ_FLD), $(WLF_SRC:.c=.o))

# libft
LIB_FLD = ./libft
LIB = $(LIB_FLD)/libft.a
LIB_INC = -I ./libft
LIB_LNK = -L ./libft -lft

# mlx lib
MLX_FLD = ./minilibx_macos
MLX_LIB = $(MLX_FLD)/mlx.a
MLX_INC = -I ./minilibx_macos
MLX_LNK = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit #-fno-omit-frame-pointer -fsanitize=address,shift,null,signed-integer-overflow -fsanitize=vla-bound,bool,enum,undefined

all: $(LIB) $(MLX_LIB) $(NAME)

$(WLF_OBJ_FLD)%.o: $(WLF_SRC_FLD)%.c $(WLF_INC_FLD)/wlf.h
	mkdir -p $(WLF_OBJ_FLD)
	$(CC) $(FLAGS) $(MLX_INC) $(LIB_INC) -I $(WLF_INC_FLD) -g -o $@ -c $<

$(LIB):
	make -C $(LIB_FLD)

$(MLX_LIB):
	make -C $(MLX_FLD)

$(NAME): $(WLF_OBJ)
	$(CC) $(WLF_OBJ) $(MLX_LNK) $(LIB_LNK) -g -lm -o $(NAME)

clean:
	rm -rf $(WLF_OBJ_FLD)
	make -C $(LIB_FLD) clean
	make -C $(MLX_FLD) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_FLD) fclean

re: fclean all
