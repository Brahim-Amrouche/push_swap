/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:17:12 by bamrouch          #+#    #+#             */
/*   Updated: 2022/12/18 04:15:32 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft.h"
#include "ft_printf.h"

typedef struct s_stack_group
{
    t_list a;
    t_list b;
}   t_stack_group;

t_boolean ft_manage_parser(char *input[]);

#endif 