/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_utils_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:58:02 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/09 19:58:51 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_stacks_simult(t_stack_group *stacks, int best_push[3])
{
	while (best_push[1] > 0 && best_push[2] > 0)
	{
		ft_handle_commands(stacks, "rr");
		best_push[1]--;
		best_push[2]--;
	}
	while (best_push[1] < 0 && best_push[2] < 0)
	{
		ft_handle_commands(stacks, "rrr");
		best_push[1]++;
		best_push[2]++;
	}
}

void	ft_rotate_stack_a(t_stack_group *stacks, int *stack_moves)
{
	while (*stack_moves > 0)
	{
		ft_handle_commands(stacks, "ra");
		(*stack_moves)--;
	}
	while (*stack_moves < 0)
	{
		ft_handle_commands(stacks, "rra");
		(*stack_moves)++;
	}
}

void	ft_rotate_stack_b(t_stack_group *stacks, int *stack_moves)
{
	while (*stack_moves > 0)
	{
		ft_handle_commands(stacks, "rb");
		(*stack_moves)--;
	}
	while (*stack_moves < 0)
	{
		ft_handle_commands(stacks, "rrb");
		(*stack_moves)++;
	}
}

int	ft_fix_stack_hiearchy(t_stack_group *stacks)
{
	int	limits[2];
	int	*temp;

	temp = ft_copy_stack_to_list(stacks->a);
	if (!temp)
		ft_exit_process_with_error(stacks);
	ft_find_array_limits(temp, limits);
	limits[0]--;
	temp[0]--;
	if (limits[0] > temp[0] - limits[0])
		limits[0] = limits[0] - temp[0];
	free(temp);
	return (limits[0]);
}

t_boolean	ft_is_lis_number(int *lis, int n)
{
	int	i;
	int temp;

	i = 0;
	
	while (++i < lis[0])
		if (n == lis[i])
		{
			temp = lis[lis[0] - 1];
			lis[lis[0] - 1] = lis[i];
			lis[i] = temp;
			lis[0]--;
			return (TRUE);
		}
	return (FALSE);
}
