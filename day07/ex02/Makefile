# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makafile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asvirido <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 14:27:54 by asvirido          #+#    #+#              #
#    Updated: 2018/03/22 14:12:33 by asvirido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Array

FLAGS = -c

HEAD = Array.hpp

SRC = main.cpp\

BINS = $(SRC:.cpp=.o)

all: $(NAME) $(HEAD)

$(NAME): $(BINS) $(HEAD)
	clang++ -o $(NAME) $(BINS)

%.o: %.cpp
	clang++ $(FLAGS) -o $@ -c $<

clean:
	rm -f $(BINS)

fclean: clean
	rm -f $(NAME)

re: fclean all
