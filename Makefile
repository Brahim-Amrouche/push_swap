SRCS = ${wildcard ./src/*.c}

OBJS = ${SRCS:.c=.o}

HEADERS = -I./libft -I./include 

FLAGS = -Wall -Wextra -Werror -fsanitize=address $(HEADERS)

CC = cc

NAME = push_swap

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

libft : 
	$make -c ./libft bonus

all : NAME

$(NAME) : $(OBJS) lifbt
	$(CC) $(FLAGS) ./libft/libft.a $(OBJS) -o $@

clean :
	rm -f $(OBJS)
	$make -c ./libft clean

fclean : rm
	rm -f $(NAME)
	$make -c ./libft fclean

re : fclean all

.PHONY: all libft clean fclean re
