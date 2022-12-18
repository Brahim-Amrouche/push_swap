#include "push_swap.h"



int main(int argc,char *argv[])
{
    (void) argc;
    t_stack_group stacks;
    ft_bzero(&stacks,sizeof(t_stack_group));
    ft_init_stack_group(  argv);
    ft_printf("main program");
    return (0);
}