/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:58:02 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/07 20:23:00 by bamrouch         ###   ########.fr       */
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
	{
		ft_printf("Error\n");
		exit(1);
	}
	ft_find_array_limits(temp, limits);
	limits[0]--;
	temp[0]--;
	if (limits[0] > temp[0] - limits[0])
		limits[0] = limits[0] - temp[0];
	free(temp);
	return limits[0];
}
