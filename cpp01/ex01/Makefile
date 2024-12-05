NAME = zombie

SRCS = 					\
		main.cpp 		\
		Zombie.cpp		\
		zombieHorde.cpp


OBJS = $(SRCS:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11
SANITIZE_FLAGS = -fsanitize=address,undefined -g
RM = rm -f

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

sanitize: clean
	$(CC) $(CFLAGS) $(SANITIZE_FLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re sanitize