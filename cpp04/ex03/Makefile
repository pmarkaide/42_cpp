# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 14:31:58 by pmarkaid          #+#    #+#              #
#    Updated: 2025/01/09 11:44:37 by pmarkaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brain

SRCS = 					\
		main.cpp		\
		AMateria.cpp	\
		ICharacter.cpp	\
		IMateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11 -g
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