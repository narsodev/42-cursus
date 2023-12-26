NAME	:= unnecessary_violence

SRCS	:= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJS	:= $(SRCS:.cpp=.o)

CC		:= c++

CFLAGS	:= -Wall -Wextra -Werror -std=c++98

HEADERS := Weapon.hpp HumanA.hpp HumanB.hpp

RM		:= rm -f

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re