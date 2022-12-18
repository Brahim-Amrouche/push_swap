#include "push_swap.h"

t_boolean ft_stack_has_duplication(t_list **stack, int content)
{
    t_list *temp;

    temp = *stack;
    while (temp)
    {
        if (*((int *)(temp->content)) == content)
        {
            ft_lstclear(stack,free);
            return TRUE;
        }
        temp = temp->next;
    }
    return FALSE;
}

t_boolean   ft_push_to_stack(t_list **stack, int content)
{
    t_list *new;
    int *m_content;

    if (ft_stack_has_duplication(stack,content))
        return FALSE;
    m_content = malloc(sizeof(int));
    if(!m_content)
    {
        ft_lstclear(stack,free);
        return FALSE;
    }
    *m_content = content;
    new = ft_lstnew(m_content);
    if (!new)
    {
        ft_lstclear(stack ,free);
        free(m_content);
        return FALSE;
    }
    ft_lstadd_back(stack,new);
    return TRUE;
}

t_boolean   ft_str_is_integer(const char *str ,long *res)
{
    int i;
    long temp;
    
    i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i])
        if (!ft_isdigit(str[i++]))
            return FALSE;
    temp = ft_atoi(str);
    if ( temp > INT_MAX || temp < INT_MIN)
        return FALSE;
    *res = temp;
    return TRUE;
}

t_boolean ft_parse_input(t_list **stack,int input_len, char *input_content[])
{
    int i;
    long temp;

    i = 1;
    while (i < input_len)
    {
        if (!ft_str_is_integer(input_content[i] , &temp))
            return FALSE;
        if (!ft_push_to_stack(stack,temp))
            return FALSE;
        i++;
    }
    return (TRUE);
}

void ft_init_stack_group(t_list **stack, int input_len, char *input_content[])
{
    if (input_len == 1)
        exit(0);
    if (!ft_parse_input(stack, input_len, input_content))
    {
        ft_printf("Error\n");
        exit(1);
    }
}
