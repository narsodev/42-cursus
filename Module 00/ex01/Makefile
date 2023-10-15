NAME	:= phonebook

SRCS	:= PhoneBook.class.cpp Contact.class.cpp main.cpp

OBJS	:= $(SRCS:.cpp=.o)

CC		:= g++

CFLAGS	:= -Wall -Wextra -Werror -std=c++98

HEADERS := PhoneBook.class.hpp Contact.class.hpp

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