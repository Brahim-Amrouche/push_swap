/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:26:37 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/09 16:24:42 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_least_moves_a(t_stack_group *stacks, int value)
{
	int	pos;
	int	limits[2];
	int	*stack_list;

	stack_list = ft_copy_stack_to_list(stacks->a);
	if (!stack_list)
		ft_exit_process_with_error(stacks);
	ft_find_array_limits(stack_list, limits);
	pos = 1;
	while (pos < stack_list[0] - 1)
	{
		if (stack_list[pos] < value && stack_list[pos + 1] > value)
			break ;
		pos++;
	}
	if (value < stack_list[limits[0]] || value > stack_list[limits[1]])
		pos = limits[1];
	pos %= (stack_list[0] - 1);
	if (pos > (stack_list[0] - 1) - pos)
		pos = pos - (stack_list[0] - 1);
	free(stack_list);
	return (pos);
}

void	ft_find_best_push(t_stack_group *stacks, int res[3])
{
	t_list	*stack_temp;
	int		stack_len;
	int		temp[3];

	stack_len = ft_lstsize(stacks->b);
	stack_temp = (stacks->b)->next;
	res[0] = *((int *)stacks->b->content);
	res[1] = ft_find_least_moves_a(stacks, res[0]);
	res[2] = 0;
	temp[0] = 1;
	while (stack_temp)
	{
		temp[1] = ft_find_least_moves_a(stacks,
										*((int *)stack_temp->content));
		if (temp[0] <= stack_len - temp[0])
			temp[2] = temp[0];
		else
			temp[2] = temp[0] - stack_len;
		ft_set_best_b_push(*((int *)stack_temp->content), res, temp);
		temp[0]++;
		stack_temp = stack_temp->next;
	}
}

void	ft_opt_simult_rotate(t_stack_group *stacks,int *stack_moves)
{
	while (stack_moves[1] > 0 && stack_moves[2] > 0)
	{
		ft_rotate_stack(&(stacks->a));
		ft_rotate_stack(&(stacks->b));
		stack_moves[1]--;
		stack_moves[2]--;
	}
	while (stack_moves[1] < 0 && stack_moves[2] < 0)
	{
		ft_reverse_rotate_stack(&(stacks->a));
		ft_reverse_rotate_stack(&(stacks->b));
		stack_moves[1]++;
		stack_moves[2]++;
	}
}

void	ft_opt_rotate_stack(t_list **stack, int *stack_moves)
{
	while (*stack_moves > 0)
	{
		ft_rotate_stack(stack);
		(*stack_moves)--;
	}
	while (*stack_moves < 0)
	{
		ft_reverse_rotate_stack(stack);
		(*stack_moves)++;
	}
}

int	ft_fix_path(t_stack_group *stacks,int *moves)
{
	int cpy_moves[3];
	
	cpy_moves[0] = moves[0];
	cpy_moves[1] = moves[1];
	cpy_moves[2] = moves[2];
	ft_opt_simult_rotate(stacks,cpy_moves);
	ft_opt_rotate_stack(&(stacks->a),&(cpy_moves[1]));
	ft_opt_rotate_stack(&(stacks->b),&(cpy_moves[2]));
	ft_push_element_to_stack(&(stacks->a),&(stacks->b));
	
	return (ft_abs(moves[1]) + ft_abs(moves[2]) + 1);
}

t_list	*ft_copy_stack(t_stack_group *stacks,t_list *cpy_stack)
{
	t_list	*cpy_temp;
	t_list	*temp;
	int	*content;
	
	cpy_temp = NULL;
	while (cpy_stack)
	{
		content = malloc(sizeof(int));
		if (!content)
		{
			ft_lstclear(&cpy_temp,free);
			ft_exit_process_with_error(stacks);
		}
		*content = *(int *) cpy_stack->content;
		temp = ft_lstnew(content);
		if (!temp)
		{
			ft_lstclear(&cpy_temp,free);
			ft_exit_process_with_error(stacks);
		}
		ft_lstadd_back(&cpy_temp,temp);
		cpy_stack = cpy_stack->next;
	}
	return cpy_temp;
}

t_stack_group	*ft_copy_stack_group(t_stack_group *stacks)
{
	t_stack_group *group;

	group = malloc(sizeof(t_stack_group) * 1);
	if (!group)
		ft_exit_process_with_error(stacks);
	group->a = ft_copy_stack(stacks,stacks->a);
	group->b = ft_copy_stack(stacks,stacks->b);	
	return group;
}
