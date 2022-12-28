/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:17:03 by bamrouch          #+#    #+#             */
/*   Updated: 2022/12/28 22:48:10 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_boolean   ft_is_smallest_lis_element(int **lis,int value)
{
    // If smallest element in lis end elements create a new lis with len 1;
    int i;
    int sub_lis_len;

    i = 1;
    while (i < lis[0][0])
    {
        sub_lis_len = lis[i][0];
        if (value > lis[i++][sub_lis_len - 1])
            return FALSE;
    }   
    ft_malloc_sub_lis(lis,2,value);
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
            // if not biggest lis end element replace with the one smaller than it
            ft_malloc_sub_lis(lis,i,value);
            return FALSE;
        }
        i++;
    }
    // If biggest lis end element add it to the longest existing lis
    ft_malloc_sub_lis(lis,(*lis)[0][0],value);
    return TRUE;
}

void    ft_push_new_lis(int ***lis ,int list_len,int value)
{
    int *new_sub_lis;
    int **new_lis;
    int i;

    new_lis = malloc(((*lis)[0][0] + 1) * sizeof(int *));
    if (!new_lis)
        return
    i = -1;
    while (++i < (*lis)[0][0])
        new_lis[i] = (*lis)[i];
    free(*lis);
    new_lis[0][0]++;
    new_sub_lis = malloc((list_len + 1) * sizeof(int));
    if (!new_sub_lis)
        return;
    i = -1;
    while (++i < list_len)
        new_sub_lis[i] = new_lis[new_lis[0][0] - 2][i];
    new_lis[new_lis[0][0] - 1] = new_sub_lis;
    new_sub_lis[list_len] = value;
    new_sub_lis[0]++;
    *lis = new_lis;
}

void    ft_malloc_sub_lis(int ***lis,int index,int value)
{
    int list_len;

    list_len = (*lis)[index - 1][0];
    if (index == (*lis)[0][0])
        ft_push_new_lis(lis, list_len, value);
    else
        (*lis)[index - 1][list_len - 1] = value;
}

int *ft_find_lis(t_list *stack_a)
{  
    int temp;
    int **lis;

    lis = malloc(2 * sizeof(int *)); 
    lis[0] = malloc(1 * sizeof(int)); // first lis element is the lenght of the list 
    lis[0][0] = 2;// will have 2 elements at the start
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