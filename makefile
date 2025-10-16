NAME        := cub3D
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
MLXDIR      := minilibx-linux
MLXFLAGS    := -L$(MLXDIR) -lmlx -lXext -lX11 -lm
INCLUDE_DIR := includes

SRC := \
	main.c \
	init.c \
	cleanup.c \
	validations_and_parsing/colors.c \
	validations_and_parsing/data.c \
	validations_and_parsing/fill_map1.c \
	validations_and_parsing/fill_map2.c \
	validations_and_parsing/free_utils.c \
	validations_and_parsing/map.c \
	validations_and_parsing/validations_main.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	utils/utils4.c \
	utils/utils3.c \
	utils/utils2.c \
	utils/utils1.c \
	game/game.c \
	game/raycasting_dda.c \
	game/raycasting_init.c \
	game/rendering.c \
	game/key_handlers.c \
	game/movement.c \
	game/player.c \
	game/position.c \
	game/rotations.c \
	game/textures.c \


OBJ_DIR := object
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(MLXDIR)/libmlx.a $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I$(INCLUDE_DIR) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(MLXDIR) -c $< -o $@

$(MLXDIR)/libmlx.a:
	@$(MAKE) -C $(MLXDIR)

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
