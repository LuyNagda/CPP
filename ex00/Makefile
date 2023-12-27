# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 15:04:23 by lunagda           #+#    #+#              #
#    Updated: 2023/12/27 18:17:20 by lunagda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	megaphone
CC				=	c++
FLAGS			=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -rf
SOURCE			=	megaphone.cpp

all: $(NAME)

$(NAME):	$(SOURCE)
	@ $(CC) $(FLAGS) $(SOURCE) -o $(NAME)

clean:
	@$(RM) $(NAME)

fclean: clean

re: clean all

.PHONY: all clean fclean re