NAME	:= polymorphism
WRONG_NAME := polymorphism_wrong

SRCS	:= main.cpp Animal.cpp Dog.cpp Cat.cpp
OBJS	:= $(SRCS:.cpp=.o)

CC		:= c++

CFLAGS	:= -Wall -Wextra -Werror -std=c++98

HEADERS := Animal.hpp Dog.hpp Cat.hpp

WRONG_SRCS	:= wrong_main.cpp WrongAnimal.cpp WrongDog.cpp WrongCat.cpp
WRONG_OBJS	:= $(WRONG_SRCS:.cpp=.o)
WRONG_HEADERS := WrongAnimal.hpp WrongDog.hpp WrongCat.hpp

RM		:= rm -f

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

wrong: $(WRONG_NAME)

$(WRONG_NAME): $(WRONG_OBJS) $(WRONG_HEADERS)
	$(CC) $(CFLAGS) -o $(WRONG_NAME) $(WRONG_OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(WRONG_OBJS)

fclean: clean
	$(RM) $(NAME) $(WRONG_NAME)

re: fclean all

.PHONY: all clean fclean re