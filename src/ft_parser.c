#include "push_swap.h"

t_list  *ft_push_to_stack(t_list *stack, int content)
{
    t_list *new;
    int *m_content;

    m_content = malloc(sizeof(int));
    *m_content = content;
    new = ft_lstnew(m_content);
    if (!new)
        return NULL;
    ft_lstadd_back(&stack,new);
    
}

t_boolean ft_input_is_numbers(t_list *stack,int input_len, char *input_content[])
{
    int i;
    int j;
    long temp;

    i = 1;
    while (i < input_len)
    {
        j = 0;
        while (input_content[i][j])
            if (!ft_isdigit(input_content[i][j++]))
                break;
        temp = ft_atoi(input_content[i]);
        if ( temp > INT_MAX || temp < INT_MIN)
            break;
        ft_lstadd_back(stack,ft_lstnew())        
    }
    if (i < input_len)
    {
        write(2,"Error\n",6);
        exit(1);
    }
    return (TRUE);
}


void ft_init_stack_group(t_list *stack, int input_len, char *input_content[])
{
    if (input_len == 1)
        exit(0);
    if (ft_)
}
