NAME = Zombie

SRC = main.cpp newZombie.cpp Zombie.cpp randomChump.cpp

CC = c++
FLAG = -Werror -Wextra -Wall -std=c++98

NOC		= \033[0m
GREEN	= \033[1;32m
RED		= \033[1;31m

%.o: %.cpp
	@echo "$(GREEN)[OK]$(NOC)" "\c"
	$(CC) $(FLAG) -c $< -o $@

OBJS = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(SRC) $(OBJS)
	$(CC) $(FLAG) $(SRC) -o $(NAME)
	@echo "$(GREEN) $(NAME) Generated! ✓ $(NOC)"

clean :
	rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED) $(NAME) deleted $(NOC)"

re : fclean all

.PHONY: all clean fclean re