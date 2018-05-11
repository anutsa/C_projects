NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror -g

FDF_SRC_FLD = src/
FDF_OBJ_FLD = obj/
FDF_INC_FLD = includes/

FDF_SRC = main.c read.c rotate.c validation.c img.c
FDF_OBJ = $(addprefix $(FDF_OBJ_FLD), $(FDF_SRC:.c=.o))

# libft
LIB_FLD = ./libft
LIB = $(LIB_FLD)/libft.a
LIB_INC = -I ./libft
LIB_LNK = -L ./libft -lft

# mlx lib
MLX_FLD = ./minilibx_macos
MLX_LIB = $(MLX_FLD)/mlx.a
MLX_INC = -I ./minilibx_macos
MLX_LNK = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

all: $(LIB) $(MLX_LIB) $(NAME)

$(FDF_OBJ_FLD)%.o: $(FDF_SRC_FLD)%.c $(FDF_INC_FLD)
	mkdir -p $(FDF_OBJ_FLD)
	$(CC) $(FLAGS) $(MLX_INC) $(LIB_INC) -I $(FDF_INC_FLD) -g -O3 -o $@ -c $<

$(LIB):
	make -C $(LIB_FLD)

$(MLX_LIB):
	make -C $(MLX_FLD)

$(NAME): $(FDF_OBJ)
	$(CC) $(FDF_OBJ) $(MLX_LNK) $(LIB_LNK) -g -O3 -lm -o $(NAME)

clean:
	rm -rf $(FDF_OBJ_FLD)
	make -C $(LIB_FLD) clean
	make -C $(MLX_FLD) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_FLD) fclean

re: fclean all
