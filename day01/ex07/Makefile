# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makafile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asvirido <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 14:27:54 by asvirido          #+#    #+#              #
#    Updated: 2018/04/02 20:38:59 by asvirido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

HEAD = Replace.hpp
FLAGS = -Wall -Wextra -Werror

SRC =	main.cpp\
		Replace.cpp


BINS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(BINS) $(HEAD)
	g++ -o $(NAME) $(BINS)

%.o: %.cpp
	g++ $(FLAGS) -o $@ -c $<

clean:
	rm -f $(BINS)

fclean: clean
	rm -f $(NAME)

re: fclean all
