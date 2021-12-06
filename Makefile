NAME		=	Map_test

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

CC			=	g++

INCLUDES	=	utility.hpp iterator.hpp tree.hpp vector.hpp map.hpp

SRCS		=	main_for_map.cpp

all : $(NAME)

$(NAME) : $(SRCS) $(INCLUDES)
		@$(CC) -g -o $(NAME) $(CFLAGS) $(SRCS) -I.

clean :
		@rm -rf $(NAME)

fclean : clean
		@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re