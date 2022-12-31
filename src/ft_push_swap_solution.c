/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:42:20 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/01 00:33:40 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_push_non_lis_to_b(t_stack_group *stacks,int *lis)
{
    t_list *temp;
    t_list *next;
    int i;
    int stack_len;

    stack_len = ft_lstsize(stacks->a);
    temp = stacks->a;
    i = 1;
    while(stack_len--)
    {
        next = temp->next;
        if (i < lis[0] && *((int *) temp->content) == lis[i] )
        {
            ft_handle_commands(stacks,"ra");
            i++;
        }
        else
            ft_handle_commands(stacks,"pb");
        temp = next;
    }
}

int ft_find_least_moves_a(int *lis,int value)
{
    int pos;
    int stack_a_len;

    pos = 1;
    while (pos < lis[0] && lis[pos] < value)
        pos++;
    pos--;
    stack_a_len = lis[0] - 1;    
    if (pos <= stack_a_len - pos)
        return pos;
    else
        return pos - stack_a_len;
}

int *ft_find_best_push(t_stack_group *stacks,int *lis)
{
    t_list  *stack_temp;
    int     stack_len;
    int     *res;
    int     temp[3];
    
    res = malloc(3 * sizeof(int));
    if (!res)
        return NULL;
    stack_len = ft_lstsize(stacks->b);
    stack_temp = (stacks->b)->next;
    res[0] = *((int *)stacks->b->content); 
    res[1] = ft_find_least_moves_a(lis,res[0]);
    res[2] = 0;
    temp[0] = 1;
    while (stack_temp)
    {   
        temp[1] = ft_find_least_moves_a(lis, *((int *)stack_temp->content));
        if ( temp[0] <= stack_len - temp[0] )
            temp[2] = temp[0];
        else
            temp[2] = temp[0] - stack_len;
        ft_set_best_b_push(*((int *)stack_temp->content),res,temp);
        temp[0]++;
        stack_temp = stack_temp->next;
    }
    return res;
} 

void    ft_find_stack_solution(t_stack_group *stacks, int *lis)
{
    int *best_push;
    ft_push_non_lis_to_b(stacks,lis);
    best_push = ft_find_best_push(stacks,lis);
    // now after finding the optiomal push it's time to apply it
}