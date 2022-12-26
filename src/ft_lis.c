/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:17:03 by bamrouch          #+#    #+#             */
/*   Updated: 2022/12/26 20:33:51 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_boolean   ft_is_smallest_lis_element(int **lis,int value)
{
    int i;
    int sub_lis_len;

    i = 1;
    while (i < lis[0][0])
    {
        sub_lis_len = lis[i][0];
        if (value > lis[i++][sub_lis_len - 1])
            return FALSE;
    }   
    ft_malloc_sub_lis(lis,1,value);
    return TRUE;
}

t_boolean   ft_is_largest_lis_element(int ***lis, int value)
{
    int i;
    int sub_lis_len;
    
    i = 1;
    while (i < (*lis)[0][0])
    {
        sub_lis_len = lis[i][0];
        if(value < lis[i][sub_lis_len - 1])
        {
            ft_malloc_sub_lis(lis,i - 1,value);
            return FALSE;
        }
        i++;
    }
    ft_malloc_sub_lis(lis,(*lis)[0][0],value);
    return TRUE;
}

void    ft_malloc_sub_lis(int ***lis,int index,int value)
{
    int list_len;
    int *new_sub_lis;    
    int **new_lis;
    int i;

    list_len = (*lis)[index - 1][0];
    if (index == (*lis)[0][0])
    {
        new_lis = malloc(sizeof(int *) * ((*lis)[0][0] + 1));
        if (!new_lis)
            return;
        i = 0;
        while(i < (*lis)[0][0])
        {
            new_lis[i] = (*lis)[i];
            i++;
        }
        free(*lis);
        new_sub_lis = malloc(sizeof(int) * (list_len + 1));
        if (!new_sub_lis)
            return;
        new_lis[index] = new_sub_lis;
        new_lis[0][0]++;
        i = 0;
        while (i < list_len)
        {
            new_sub_lis[i]= new_lis[index - 1][i];
            i++;
        }
        new_sub_lis[i] = value;
        new_sub_lis[0]++;
        *lis = new_lis;
    }   
}

int *ft_find_lis(t_list *stack_a)
{  
    int temp;
    int **lis;

    lis = malloc(2 * sizeof(int *));
    lis[0] = malloc(1 * sizeof(int));
    lis[0][0] = 2;
    lis[1] = malloc(2 * sizeof(int));
    lis[1][0] = 2;
    lis[1][1] = *((int *) stack_a->content);
    stack_a = stack_a->next;
    while (stack_a)
    {
        temp =  *((int *) stack_a->content);
        if (ft_is_smallest_lis_element(&lis, temp))
            continue;
        else if (ft_is_largest_lis_element(&lis, temp))
            continue;
        stack_a = stack_a->next;
    }
}