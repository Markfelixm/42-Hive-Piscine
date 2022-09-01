# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 12:54:53 by marmulle          #+#    #+#              #
#    Updated: 2022/08/28 21:02:32 by marmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := rush-2
SRCS := main.c utils.c gen_rush.c gen_rush_parse_pos.c

.PHONY: all
all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(SRCS) -o $(NAME)

.PHONY: clean
clean:
	rm -f *.o

.PHONY: fclean
fclean:
	rm -f $(NAME)

.PHONY: re
re: fclean all
