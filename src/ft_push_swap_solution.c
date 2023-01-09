/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:42:20 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/09 18:19:02 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_boolean ft_is_lis_number(int *lis, int n)
{
	int i;

	i = 1;
	while (i < lis[0])
		if (n == lis[i++])
			return TRUE;
	return FALSE;
}

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
		if (ft_is_lis_number(lis,*((int *)temp->content)))
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

int	*ft_find_longest_lis(t_stack_group *stacks)
{
	t_list *cpy_stack_a;
	int	stack_a_len;
	int	*longest_lis[2];
	
	cpy_stack_a = ft_copy_stack(stacks,stacks->a);
	stack_a_len = ft_lstsize(stacks->a);
	longest_lis[1] = ft_find_lis(cpy_stack_a);
	while(--stack_a_len)
	{
		ft_rotate_stack(&cpy_stack_a);
		longest_lis[0] = ft_find_lis(cpy_stack_a);
		if (longest_lis[0][0] > longest_lis[1][0])
		{
			free(longest_lis[1]);
			longest_lis[1] = longest_lis[0];
		}
		else
			free(longest_lis[0]);
	}
	ft_lstclear(&cpy_stack_a,free);
	return longest_lis[1];
}

void	ft_find_stack_solution(t_stack_group *stacks)
{
	int	*lis;

	lis = ft_find_longest_lis(stacks);
	if (!lis)
		ft_exit_process_with_error(stacks);
	ft_push_non_lis_to_b(stacks,lis);
	free(lis);
	ft_sort_stack(stacks);
}
