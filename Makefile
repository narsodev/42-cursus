NAME		:= so_long
BONUS		:= so_long

SRC_DIR		:= src
OBJ_DIR		:= obj

FILES		:= main checker checker_utils events free init movement parser \
				player_movement player_utils player render

SRCS		:= $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))
OBJS		:= $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))

LIBFT		:= libft
MLX42		:= MLX42
GLFW		:= ~/.brew/opt/glfw/lib

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror

INCLUDE		:= -I $(LIBFT) -I . -I MLX42/include/MLX42

LIB			:= -L $(LIBFT) -l ft -L $(MLX42) -l mlx42 -L $(GLFW) -l glfw 

RM			:= rm -rf

all:		$(NAME)

clean:
	$(RM) $(OBJ_DIR)
	make clean -C $(LIBFT)
	make clean -C $(MLX42)

fclean:		clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)
	make fclean -C $(MLX42)

re:			fclean all

$(NAME):	$(OBJS) | $(LIBFT)/libft.a $(MLX42)/libmlx42.a
	gcc $(LIB) -o $(NAME) $^

$(LIBFT)/libft.a:
	make -C $(LIBFT)

$(MLX42)/libmlx42.a:
	make -C $(MLX42)

$(OBJS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

.PHONY: all clean fclean re
