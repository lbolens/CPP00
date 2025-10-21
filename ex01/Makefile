# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 10:10:08 by lbolens           #+#    #+#              #
#    Updated: 2025/10/21 10:19:14 by lbolens          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      := phonebook
CXX       := c++
CXXFLAGS  := -Wall -Wextra -Werror -std=c++98
INCLUDES  := -I .
SRCS      := ex01.cpp
OBJS      := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.cpp PhoneBook.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

