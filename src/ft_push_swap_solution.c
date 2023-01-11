/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:02:51 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/11 21:07:13 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_non_lis_to_b(t_stack_group *stacks, int *lis)
{
	t_list	*temp;
	t_list	*next;
	int		stack_len;
	int		non_lis_len;

	stack_len = ft_lstsize(stacks->a);
	temp = stacks->a;
	non_lis_len = stack_len - (lis[0] - 1);
	while (stack_len--)
	{
		next = temp->next;
		if (ft_is_lis_number(lis, *((int *)temp->content)))
			ft_handle_commands(stacks, "ra");
		else if (non_lis_len > 0)
		{
			ft_handle_commands(stacks, "pb");
			non_lis_len--;
		}
		else
			break ;
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

int	*ft_find_longest_lis(t_stack_group *stacks)
{
	t_list	*cpy_stack_a;

	cpy_stack_a = ft_copy_stack(stacks, stacks->a);
	return (ft_iterate_for_longest_lis(stacks, &cpy_stack_a));
}

void	ft_find_stack_solution(t_stack_group *stacks)
{
	int	*lis;
	int	i;

	if (!stacks->a)
		return ;
	lis = ft_find_longest_lis(stacks);
	if (!lis)
		ft_exit_process_with_error(stacks);
	i = 1;
	ft_handle_three_elements_stack(stacks, &lis);
	ft_push_non_lis_to_b(stacks, lis);
	free(lis);
	ft_sort_stack(stacks);
}
