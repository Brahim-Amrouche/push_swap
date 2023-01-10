/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:42:20 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/10 15:19:35 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_non_lis_to_b(t_stack_group *stacks, int *non_lis)
{
	t_list	*temp;
	t_list	*next;
	int		stack_len;

	stack_len = ft_lstsize(stacks->a);
	temp = stacks->a;
	while (stack_len--)
	{
		next = temp->next;
		if (ft_is_lis_number(non_lis, *((int *)temp->content)))
			ft_handle_commands(stacks, "pb");
		else if (non_lis[0] == 1)
			break;
		else
			ft_handle_commands(stacks, "ra");
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
	int		stack_a_len;
	int		*longest_lis[2];

	cpy_stack_a = ft_copy_stack(stacks, stacks->a);
	stack_a_len = ft_lstsize(stacks->a);
	longest_lis[1] = ft_find_lis(cpy_stack_a);
	while (--stack_a_len)
	{
		ft_rotate_stack(&cpy_stack_a);
		longest_lis[0] = ft_find_lis(cpy_stack_a);
		if (longest_lis[0][0] >= longest_lis[1][0])
		{
			free(longest_lis[1]);
			longest_lis[1] = longest_lis[0];
		}
		else
			free(longest_lis[0]);
	}
	ft_lstclear(&cpy_stack_a, free);
	return (longest_lis[1]);
}

void	ft_fill_non_lis(t_list *stack_a,int *lis ,int *non_lis)
{
	int i;
	int j;
	
	i = 1;
	j = 1;
	while(stack_a)
	{
		if (!ft_is_lis_number(lis, *(int *)stack_a->content))
			non_lis[j++] = *(int *)stack_a->content;
		else
			i++; 
		stack_a = stack_a->next;
	}
}

int	*ft_find_non_lis(t_stack_group *stacks, int *lis)
{
	int *non_lis;
	int	non_lis_size;
	
	non_lis_size = ft_lstsize(stacks->a) + 1 - (lis[0] - 1);
	non_lis = malloc(sizeof(int) * non_lis_size);
	if (!non_lis)
	{
		free(lis);
		ft_exit_process_with_error(stacks);
	}
	non_lis[0] = non_lis_size;
	ft_fill_non_lis(stacks->a,lis,non_lis);
	return non_lis;
}

void	ft_find_stack_solution(t_stack_group *stacks)
{
	int	*lis;
	int *non_lis;
	int	stack_size;

	lis = ft_find_longest_lis(stacks);
	stack_size = ft_lstsize(stacks->a);
	if (stack_size <= 3 && lis[0] - 1 != stack_size)
	{	
		ft_handle_commands(stacks, "sa");
		lis = ft_find_longest_lis(stacks);
	}
	if (!lis)
		ft_exit_process_with_error(stacks);
	non_lis = ft_find_non_lis(stacks,lis);
	free(lis);
	ft_push_non_lis_to_b(stacks, non_lis);
	free(non_lis);
	ft_sort_stack(stacks);
}
