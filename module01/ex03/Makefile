NAME = Violence

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

CC = clang++
FLAGS = -Werror -Wextra -Wall -std=c++98

NOC		= \033[0m
GREEN	= \033[1;32m
RED		= \033[1;31m

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(FLAG) $(SRC) -o $(NAME)
	@echo "$(GREEN) $(NAME) Generated! ✓ $(NOC)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED) $(NAME) deleted $(NOC)"

clean :
	@rm -f $(NAME)
	
re : fclean all