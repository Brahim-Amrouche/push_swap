/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:17:12 by bamrouch          #+#    #+#             */
/*   Updated: 2022/12/23 00:04:09 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack_group
{
	t_list	*a;
	t_list	*b;
}			t_stack_group;

/*  Inpu Parsing */
void		ft_init_stack_group(t_list **stack, int input_len,
				char *input_content[]);

/*  Stack Commands */
void		ft_swap_stack_top_elements(t_list **p_stack);
void		ft_push_element_to_stack(t_list **p_stack_a, t_list **p_stack_b);
void		ft_rotate_stack(t_list **p_stack);
void		ft_reverse_rotate_stack(t_list **p_stack);
void		ft_handle_commands(t_stack_group *stacks, char *cmd);

/* Stack Solution */
void    ft_sort_stack(t_stack_group *stacks);

#endif