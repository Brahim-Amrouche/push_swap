/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:02:51 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/13 22:02:31 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_non_lis_to_b(t_stack_group *stacks, int *lis,
		t_boolean sort_stack_b)
{
	int	non_lis_len;
	int	pivot;
	int	temp;

	non_lis_len = ft_lstsize(stacks->a) - (lis[0] - 1);
	pivot = lis[lis[0] / 2];
	while (non_lis_len > 0)
	{
		temp = *(int *)stacks->a->content;
		if (ft_is_lis_number(lis, temp))
			ft_handle_commands(stacks, "ra");
		else
		{
			ft_handle_commands(stacks, "pb");
			if (sort_stack_b && pivot > temp)
				ft_handle_commands(stacks, "rb");
			non_lis_len--;
		}
	}
}

void	ft_sort_stack(t_stack_group *stacks)
{
	int	best_push[3];
	int	rotation_fix;

	while (stacks->b)
	{
		ft_find_best_push(stacks, best_push);
		ft_rotate_stacks_simult(stacks, best_push);
		ft_rotate_stack_a(stacks, &(best_push[1]));
		ft_rotate_stack_b(stacks, &(best_push[2]));
		ft_handle_commands(stacks, "pa");
	}
	rotation_fix = ft_fix_stack_hiearchy(stacks);
	while (rotation_fix > 0)
	{
		ft_handle_commands(stacks, "ra");
		rotation_fix--;
	}
	while (rotation_fix < 0)
	{
		ft_handle_commands(stacks, "rra");
		rotation_fix++;
	}
}

int	*ft_find_longest_lis(t_stack_group *stacks)
{
	t_list	*cpy_stack_a;

	cpy_stack_a = ft_copy_stack(stacks, stacks->a);
	return (ft_iterate_for_longest_lis(stacks, &cpy_stack_a));
}

void	ft_find_stack_solution(t_stack_group *stacks)
{
	int	*lis;

	if (!stacks->a)
		return ;
	lis = ft_find_longest_lis(stacks);
	if (!lis)
		ft_exit_process_with_error(stacks);
	if (!ft_handle_five_elements_stacks(stacks, &lis))
		ft_push_non_lis_to_b(stacks, lis, TRUE);
	free(lis);
	ft_sort_stack(stacks);
}
