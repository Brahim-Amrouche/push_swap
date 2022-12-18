#ifndef TESTER_H
# define TESTER_H
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#ifndef BONUS_TESTS
# define BONUS_TESTS 0
#endif

void	print_white(void);
void	print_black(void);
void	mandatory(void);
void    bonus(void);
void	print_test_result(int i, char *test_message);

#endif