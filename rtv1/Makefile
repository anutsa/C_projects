NAME = RTv1
CC = gcc
FLAGS = -Wall -Wextra -Werror -g

RTV_SRC_FLD = src/
RTV_OBJ_FLD = obj/
RTV_INC_FLD = includes/

RTV_SRC = main.c set_scene.c operations.c sphere.c plane.c cone.c\
		  cylinder.c mixed.c camera.c init_scene_params.c init_shape_params.c\
		  color.c
RTV_OBJ = $(addprefix $(RTV_OBJ_FLD), $(RTV_SRC:.c=.o))

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

$(RTV_OBJ_FLD)%.o: $(RTV_SRC_FLD)%.c $(RTV_INC_FLD)
	mkdir -p $(RTV_OBJ_FLD)
	$(CC) $(FLAGS) $(MLX_INC) $(LIB_INC) -I $(RTV_INC_FLD) -g -O3 -o $@ -c $<

$(LIB):
	make -C $(LIB_FLD)

$(MLX_LIB):
	make -C $(MLX_FLD)

$(NAME): $(RTV_OBJ)
	$(CC) $(RTV_OBJ) $(MLX_LNK) $(LIB_LNK) -g -O3 -lm -o $(NAME)

clean:
	rm -rf $(RTV_OBJ_FLD)
	make -C $(LIB_FLD) clean
	make -C $(MLX_FLD) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_FLD) fclean

re: fclean all
