# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makafile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asvirido <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 14:27:54 by asvirido          #+#    #+#              #
#    Updated: 2017/03/12 21:39:03 by asvirido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

HEAD = Contact.class.hpp

FLAGS = -Wall -Wextra #-Werror

SRC =	Contact.class.cpp\
		run.cpp\
		DataBase.class.cpp\

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
