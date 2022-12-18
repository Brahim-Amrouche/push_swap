SRCS = ${wildcard ./src/*.c}

OBJS = ${SRCS:.c=.o}

HEADERS = -I./libft/headers -I./libft/libft -I./include 

FLAGS = -Wall -Wextra -Werror -fsanitize=address $(HEADERS)

CC = cc

NAME = push_swap

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

all : $(NAME)

libft : 
	make -C ./libft bonus

$(NAME) : $(OBJS) libft
	$(CC) $(FLAGS) ./libft/libftprintf.a $(OBJS) -o $@

clean :
	rm -f $(OBJS)
	make -C ./libft clean

fclean : clean
	rm -f $(NAME)
	make -C ./libft fclean

re : fclean all

.PHONY: all libft clean fclean re
