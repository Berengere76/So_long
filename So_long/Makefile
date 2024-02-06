NAME := so_long

CC := cc
RM := rm -f

CLINKS		= -ldl -lglfw -pthread -lm
CFLAGS		= -g -Wall -Wextra -Werror
MLX			= minilibx
LIBMLX 		= $(MLX)/libmlx42.a

FT			= Libft
LIBFT		= $(FT)/libft.a

SOURCE := so_long.c texture.c map.c perso.c movement.c game.c error.c check_path.c
OBJ 	= $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) $(CLINKS)

$(LIBMLX): $(MLX)
	cmake $(MLX) -B $(MLX)	
	$(MAKE) -C $(MLX)
	
$(LIBFT): $(FT)
	$(MAKE) -C $(FT)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
		make clean -C $(MLX)
		rm -rf $(NAME)

re: fclean all

.PHONY:		all bonus clear clean fclean re
