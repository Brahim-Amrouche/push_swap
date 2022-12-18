SRCS = ./srcs/ft_converters_1.c ./srcs/ft_converters_utils.c ./srcs/ft_flags_applier.c ./srcs/ft_flags_parser.c ./srcs/ft_printf.c

SRCS_OBJS = ${SRCS:.c=.o}

CC = cc

HEADERS = -I./headers -I./libft

FLAGS = -Wall -Wextra -Werror $(HEADERS)

NAME = libftprintf.a

$(NAME) :  $(SRCS_OBJS)
	make -C ./libft bonus
	cp ./libft/libft.a $(NAME)
	ar -rcs $@ $^

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -f $(SRCS_OBJS)
	make -C ./libft clean

fclean : clean
	rm -f $(NAME)
	make -C ./libft fclean

re : fclean all

bonus : all

.PHONY : all clean fclean re