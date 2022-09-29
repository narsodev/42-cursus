NAME		:= push_swap

SRC_DIR		:= src
OBJ_DIR		:= obj

FILES		:= main move check move sort stack
SRCS		:= $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))
OBJS		:= $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))

LIBFT		:= libft

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror

INCLUDE		:= -I $(LIBFT) -I .

LIB			:= -L $(LIBFT) -l ft

RM			:= rm -rf

all:		$(NAME)

clean:
	$(RM) $(OBJ_DIR)
	make clean -C $(LIBFT)

fclean:		clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re:			fclean all

$(NAME):	$(OBJS) | $(LIBFT)/libft.a
	gcc $(LIB) -o $@ $^

$(LIBFT)/libft.a:
	make -C $(LIBFT)

$(OBJS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

.PHONY: all clean fclean re
