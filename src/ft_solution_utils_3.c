/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:24:11 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/13 02:09:06 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_free_longest_lis(t_stack_group *stacks, int *l_lis)
{
	if (l_lis)
		free(l_lis);
	ft_exit_process_with_error(stacks);
}

int	*ft_iterate_for_longest_lis(t_stack_group *stacks, t_list **cpy_stack_a)
{
	int	stack_a_len;
	int	*l_lis[2];

	stack_a_len = ft_lstsize(stacks->a);
	l_lis[1] = NULL;
	while (stack_a_len--)
	{
		l_lis[0] = ft_find_lis(*cpy_stack_a);
		if (!l_lis[0])
			ft_exit_free_longest_lis(stacks, l_lis[1]);
		if (!l_lis[1])
			l_lis[1] = l_lis[0];
		else if (l_lis[0][0] > l_lis[1][0])
		{
			free(l_lis[1]);
			l_lis[1] = l_lis[0];
		}
		else
			free(l_lis[0]);
		ft_rotate_stack(cpy_stack_a);
	}
	ft_lstclear(cpy_stack_a, free);
	return (l_lis[1]);
}

void	ft_handle_three_elements_stack(t_stack_group *stacks, int **lis)
{
	int	stack_size;

	stack_size = ft_lstsize(stacks->a);
	if (stack_size <= 5 && (*lis)[0] - 1 != stack_size)
	{
		free(*lis);
		ft_handle_commands(stacks, "sa");
		(*lis) = ft_find_longest_lis(stacks);
		if (!(*lis))
			ft_exit_process_with_error(stacks);
	}
}
