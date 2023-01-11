/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:24:11 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/11 19:26:13 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_free_longest_lis(t_stack_group *stacks, int *l_lis)
{
	free(l_lis);
	ft_exit_process_with_error(stacks);
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
