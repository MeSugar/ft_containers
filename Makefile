NAME		=	ft_containers

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

CC			=	clang++

INCLUDES	=	includes/utility.hpp includes/iterator.hpp includes/tree.hpp \
				includes/vector.hpp includes/map.hpp includes/stack.hpp includes/test.hpp

SRCS		=	sources/main.cpp sources/vector_tests.cpp sources/map_tests.cpp


all : $(NAME)

$(NAME) : $(SRCS) $(INCLUDES)
		@$(CC) -o $(NAME) $(CFLAGS) $(SRCS) -I.

clean :
		@rm -rf $(NAME)

fclean : clean
		@rm -rf $(NAME)
		@rm -rf ./vector_tests/
		@rm -rf ./map_tests/

re : fclean all

.PHONY: all clean fclean re