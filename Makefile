SRCS = ./src/ft_commands.c \
./src/ft_commands_utils.c \
./src/ft_helpers.c \
./src/ft_lis.c \
./src/ft_lis_utils.c \
./src/ft_parser.c \
./src/ft_push_swap_solution.c \
./src/ft_solution_utils_1.c \
./src/ft_solution_utils_2.c \
./src/ft_solution_utils_3.c \
./src/main.c 

BONUS_SRCS = ./src/ft_commands.c \
./src/ft_commands_utils.c \
./src/ft_helpers.c \
./src/ft_lis.c \
./src/ft_lis_utils.c \
./src/ft_parser.c \
./src/ft_push_swap_solution.c \
./src/ft_solution_utils_1.c \
./src/ft_solution_utils_2.c \
./src/ft_solution_utils_3.c\
./src/bonus/get_next_line_utils.c \
./src/bonus/get_next_line.c \
./src/bonus/ft_handle_commands.c \
./src/bonus/main.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

HEADERS = -I./libft/headers -I./libft/libft -I./include 

FLAGS = -Wall -Wextra -Werror $(HEADERS)

CC = cc

NAME = push_swap

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

all : $(NAME)

./libft/libftprintf.a : 
	make -C ./libft bonus

$(NAME) : $(OBJS) ./libft/libftprintf.a
	$(CC) $(FLAGS) ./libft/libftprintf.a $(OBJS) -o $@

bonus : $(BONUS_OBJS) ./libft/libftprintf.a
	$(CC) $(FLAGS) ./libft/libftprintf.a $(BONUS_OBJS) -o checker

clean :
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	make -C ./libft clean

fclean : clean
	rm -f $(NAME)
	rm -f checker
	make -C ./libft fclean

re : fclean all

.PHONY: all libft clean fclean re
