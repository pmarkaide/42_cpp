# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 15:42:23 by pmarkaid          #+#    #+#              #
#    Updated: 2025/05/20 19:51:06 by pmarkaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc
TEST_NAME = test_btc

SRCS = 					\
		main.cpp 		\
		BitcoinExchange.cpp

TEST_SRC = 				\
		test_btc.cpp 	\
		BitcoinExchange.cpp


OBJS = $(SRCS:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11
SANITIZE_FLAGS = -fsanitize=address,undefined -g
RM = rm -f

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

test: $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $(TEST_OBJ) -o $(TEST_NAME)


sanitize: clean
	$(CC) $(CFLAGS) $(SANITIZE_FLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(TEST_OBJ)

fclean: clean
	$(RM) $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re sanitize