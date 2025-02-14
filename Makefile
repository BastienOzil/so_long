NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = srcs

OBJS_DIR = objs

MLX_DIR = minilibx-linux

LIBFT_DIR = utils/libft

PRINTF_DIR = utils/ft_printf

GNL_DIR = utils/get_next_line

SRCS = $(SRC_DIR)/so_long.c $(SRC_DIR)/parse_map.c $(SRC_DIR)/check_map.c $(SRC_DIR)/render_map.c \
	   $(SRC_DIR)/is_map_possible.c \
       $(SRC_DIR)/key_press.c $(SRC_DIR)/start_game.c $(SRC_DIR)/load_textures.c \
       $(SRC_DIR)/exit_game.c  $(SRC_DIR)/free_map.c \

OBJS     = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MLX = $(MLX_DIR)/libmlx_Linux.a

LIBFT = $(LIBFT_DIR)/libft.a

PRINTF = $(PRINTF_DIR)/libftprintf.a

GNL = $(GNL_DIR)/libgnl.a

OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(PRINTF) $(GNL) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(GNL) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(GNL):
	make -C $(GNL_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(GNL_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(GNL_DIR)

re: fclean all

.PHONY: all clean fclean re
