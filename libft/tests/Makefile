ROOT_PROJECT = ../

LIB = libftprintf.a

SRCS = main.c test_wrap.c $(LIB) mandatory.c bonus.c

CC = cc

FLAGS = -Wall -Werror -Wextra -fsanitize=address

HEADERS = $(shell ls -R $(ROOT_PROJECT)**/*.h)

all : m b

prepare_lib : 
	@make -C $(ROOT_PROJECT) 
	@mv -f $(ROOT_PROJECT)$(LIB) ./ || (echo "failed making the project" && exit 1)
	@make -C $(ROOT_PROJECT) fclean
	@cp -f $(HEADERS) ./ || exit 0 

m : prepare_lib
	$(CC) $(FLAGS) $(SRCS) -o test 
	./test
	rm test $(LIB)

b : prepare_lib
	$(CC) $(FLAGS) $(SRCS) -o test -D BONUS_TESTS=1
	./test
	rm test $(LIB)
	