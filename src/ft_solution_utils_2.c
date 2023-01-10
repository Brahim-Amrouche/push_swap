/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:26:37 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/10 16:58:41 by bamrouch         ###   ########.fr       */
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

void	ft_set_best_b_push(int value, int *res, int *temp)
{
	int	res_score;
	int	temp_score;

	res_score = ft_abs(res[1]) + ft_abs(res[2]);
	temp_score = ft_abs(temp[1]) + ft_abs(temp[2]);
	if (temp_score < res_score)
	{
		res[0] = value;
		res[1] = temp[1];
		res[2] = temp[2];
	}
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

t_list	*ft_copy_stack(t_stack_group *stacks, t_list *cpy_stack)
{
	t_list	*cpy_temp;
	t_list	*temp;
	int		*content;

	cpy_temp = NULL;
	while (cpy_stack)
	{
		content = malloc(sizeof(int));
		if (!content)
		{
			ft_lstclear(&cpy_temp, free);
			ft_exit_process_with_error(stacks);
		}
		*content = *(int *)cpy_stack->content;
		temp = ft_lstnew(content);
		if (!temp)
		{
			ft_lstclear(&cpy_temp, free);
			ft_exit_process_with_error(stacks);
		}
		ft_lstadd_back(&cpy_temp, temp);
		cpy_stack = cpy_stack->next;
	}
	return (cpy_temp);
}

void	ft_fill_non_lis(t_list *stack_a, int *lis, int *non_lis)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (stack_a)
	{
		if (!ft_is_lis_number(lis, *(int *)stack_a->content))
			non_lis[j++] = *(int *)stack_a->content;
		else
			i++;
		stack_a = stack_a->next;
	}
}
