# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 11:45:10 by marmulle          #+#    #+#              #
#    Updated: 2022/08/24 15:40:38 by marmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft.a
INC_DIR := ./includes/
SRCS := $(wildcard ./srcs/*.c)

.PHONY: all
all: $(LIB)

$(LIB): $(SRCS)
	gcc -c $(SRCS) -I $(INC_DIR)
	ar -crs $(LIB) *.o

.PHONY: clean
clean:
	rm -f *.o

.PHONY: fclean
fclean: clean
	rm -f $(LIB)

.PHONY: re
re: fclean all
