/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:42:20 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/04 21:22:58 by bamrouch         ###   ########.fr       */
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

int	ft_find_least_moves_a(t_list *stack_a, int value)
{
	int	pos;
	int	limits[2];
	int	*stack_list;

	stack_list = ft_copy_stack_to_list(stack_a);
	if (!stack_a)
	{
		ft_printf("Error\n");
		exit(1);
	}
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
	pos = pos % (stack_list[0] - 1);
	if (pos > (stack_list[0] - 1) - pos)
		pos = pos - (stack_list[0] - 1);
	free(stack_list);
	return (pos);
}

void	ft_find_best_push(t_stack_group *stacks, int *res)
{
	t_list	*stack_temp;
	int		stack_len;
	int		temp[3];

	stack_len = ft_lstsize(stacks->b);
	stack_temp = (stacks->b)->next;
	res[0] = *((int *)stacks->b->content);
	res[1] = ft_find_least_moves_a(stacks->a, res[0]);
	res[2] = 0;
	temp[0] = 1;
	while (stack_temp)
	{
		temp[1] = ft_find_least_moves_a(stacks->a,
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

void	ft_sort_stack(t_stack_group *stacks)
{
	int	best_push[3];
	int	min[2];
	int i;
	t_list *temp;

	while (stacks->b)
	{
		ft_find_best_push(stacks, best_push);
		ft_rotate_stacks_simult(stacks, best_push);
		ft_rotate_stack_a(stacks, &(best_push[1]));
		ft_rotate_stack_b(stacks, &(best_push[2]));
		ft_handle_commands(stacks, "pa");
	}
	min[0] = 0;
	min[1] = *((int *) stacks->a->content);
	i = 1;
	temp = stacks->a->next;
	while(temp)
	{
		if (min[1] >  *(int *)temp->content)
		{
			min[0] = i;
			min[1] = *(int *)temp->content;
		}
		temp = temp->next;
		i++;
	}
	if (min[0] > ft_lstsize(stacks->a) - min[0])
		min[0] = min[0] - ft_lstsize(stacks->a);
	while (min[0] > 0)
	{
		ft_handle_commands(stacks,"ra");
		min[0]--;
	}
	while (min[0]< 0)
	{
		ft_handle_commands(stacks,"rra");
		min[0]++;
	}
}

void	ft_find_stack_solution(t_stack_group *stacks, int *lis)
{
	ft_push_non_lis_to_b(stacks, lis);
	ft_sort_stack(stacks);
	// ft_print_stacks(stacks);
}
