/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:42:20 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/08 15:56:02 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_non_lis_to_b(t_stack_group *stacks, int *lis)
{
	t_list	*temp;
	t_list	*next;
	int		i;
	int		stack_len;

	stack_len = ft_lstsize(stacks->a);
	temp = stacks->a;
	i = 1;
	while (stack_len--)
	{
		next = temp->next;
		if (i < lis[0] && *((int *)temp->content) == lis[i])
		{
			ft_handle_commands(stacks, "ra");
			i++;
		}
		else
			ft_handle_commands(stacks, "pb");
		temp = next;
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

void	ft_find_stack_solution(t_stack_group *stacks)
{
	int	*lis;

	lis = ft_find_lis(stacks->a);
	if (!lis)
		ft_exit_process_with_error(stacks);
	ft_push_non_lis_to_b(stacks, lis);
	free(lis);
	// ft_sort_stack(stacks);
	ft_printf("moves count %d\n",ft_find_best_push_path(stacks));
}
