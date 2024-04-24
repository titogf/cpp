NAME = megaphone

SRC = megaphone.cpp

CC = clang++
FLAGS = -Werror -Wextra -Wall -std=c++98

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(FLAG) $(SRC) -o $(NAME)
	@echo "$(NAME) Generated!"

fclean : clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

clean :
	@rm -f $(NAME)
	
re : fclean all