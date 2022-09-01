NAME := bsq
SRCS := srcs/algo.c srcs/input.c srcs/list.c srcs/main.c srcs/map.c srcs/metadata.c srcs/utils.c

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re