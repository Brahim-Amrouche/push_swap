/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:05:36 by bamrouch          #+#    #+#             */
/*   Updated: 2022/12/19 21:50:26 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap_stack_top_elements(t_list **p_stack)
{
    t_list *temp;
    
    if (!(*p_stack) || !((*p_stack)->next))
        return;
    temp = *p_stack;
    *p_stack = (*p_stack)->next ;
    (*p_stack)->next = temp;     
}

void ft_push_element_to_stack(t_list **p_stack_a,t_list **p_stack_b)
{
    t_list *temp;
    
    if (!(*p_stack_a) || !(*p_stack_b))
        return
    temp = *p_stack_a;
    *p_stack_a = *p_stack_b;
    (*p_stack_a)->next = temp;
    *p_stack_b = (*p_stack_b)->next;
}