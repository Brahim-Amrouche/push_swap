/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:17:12 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/04 21:15:37 by bamrouch         ###   ########.fr       */
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
int			*ft_find_lis(t_list *stack_a);
void		ft_find_stack_solution(t_stack_group *stacks, int *lis);

/* Helpers */
void		ft_free_lis(int ***lis);
int			*ft_return_lis_result(int ***lis);
void		ft_set_best_b_push(int value, int *res, int *temp);
void		ft_print_stacks(t_stack_group *stacks);

/* Solution helpers*/
int			*ft_copy_stack_to_list(t_list *stack);
void		ft_find_array_limits(int *array, int limits[2]);
void		ft_rotate_stacks_simult(t_stack_group *stacks, int best_push[3]);
void		ft_rotate_stack_a(t_stack_group *stacks, int *stack_moves);
void		ft_rotate_stack_b(t_stack_group *stacks, int *stack_moves);

#endif