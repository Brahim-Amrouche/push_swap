/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:58:02 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/04 21:14:40 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_array_limits(int *array, int limits[2])
{
	int	pos;

	if (array[1] > array[2])
	{
		limits[1] = 1;
		limits[0] = 2;
	}
	else
	{
		limits[1] = 2;
		limits[0] = 1;
	}
	pos = 3;
	while (pos < array[0])
	{
		if (array[pos] > array[limits[1]])
			limits[1] = pos;
		else if (array[pos] < array[limits[0]])
			limits[0] = pos;
		pos++;
	}
}

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