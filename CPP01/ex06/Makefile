# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 10:18:19 by luynagda          #+#    #+#              #
#    Updated: 2024/03/17 10:20:22 by luynagda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = harlFilter

HEADER = Harl.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re