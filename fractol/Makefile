NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror -g 

FRACTOL_SRC_FLD = src/
FRACTOL_OBJ_FLD = obj/
FRACTOL_INC_FLD = includes/

FRACTOL_SRC = main.c julia.c mandelbrot.c burning_ship.c image.c control.c
FRACTOL_OBJ = $(addprefix $(FRACTOL_OBJ_FLD), $(FRACTOL_SRC:.c=.o))

# libft
LIB_FLD = ./libft
LIB = $(LIB_FLD)/libft.a
LIB_INC = -I ./libft
LIB_LNK = -L ./libft -lft

# mlx lib
MLX_FLD = ./minilibx_macos
MLX_LIB = $(MLX_FLD)/mlx.a
MLX_INC = -I ./minilibx_macos
MLX_LNK = -L ./minilibx_macos -lpthread -lmlx -framework OpenGL -framework AppKit

all: $(LIB) $(MLX_LIB) $(NAME)

$(FRACTOL_OBJ_FLD)%.o: $(FRACTOL_SRC_FLD)%.c $(FRACTOL_INC_FLD)
	mkdir -p $(FRACTOL_OBJ_FLD)
	$(CC) $(FLAGS) $(MLX_INC) $(LIB_INC) -I $(FRACTOL_INC_FLD) -g -O3 -o $@ -c $<

$(LIB):
	make -C $(LIB_FLD)

$(MLX_LIB):
	make -C $(MLX_FLD)

$(NAME): $(FRACTOL_OBJ)
	$(CC) $(FRACTOL_OBJ) $(MLX_LNK) $(LIB_LNK) -g -O3 -lm -o $(NAME)

clean:
	rm -rf $(FRACTOL_OBJ_FLD)
	make -C $(LIB_FLD) clean
	make -C $(MLX_FLD) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_FLD) fclean

re: fclean all
