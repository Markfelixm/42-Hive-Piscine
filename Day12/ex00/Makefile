# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 12:32:25 by marmulle          #+#    #+#              #
#    Updated: 2022/08/24 13:02:46 by marmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_display_file
SRC := ft_display_file.c
FLAGS := -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -o $(NAME)

.PHONY: clean
clean:
	rm -f *.o

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
