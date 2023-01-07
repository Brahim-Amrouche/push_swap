/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_optimisers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:26:37 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/07 20:23:29 by bamrouch         ###   ########.fr       */
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

void    ft_stack_iteration_best_path(t_stack_group *stacks,t_list *temp_stack_b,int *** res_best_path)
{
    int temp_stack_b_len;
    int **best_moves_path;
    int best_push[2][3];
    int i;

    temp_stack_b_len = ft_lstsize(temp_stack_b);
    best_moves_path = malloc(temp_stack_b_len * sizeof(int *));
    if (!best_moves_path)
        ft_exit_process_with_error(stacks);
    i = 0;
    best_push[1][];
    while (temp_stack_b)
    {
        temp_stack_b = temp_stack_b->next;
        ft_find_best_push(stacks,best_push);
        
    }
}

void    ft_find_best_push_path(t_stack_group *stacks)
{
    int stack_b_len;
    int **best_moves;
    int total_moves_count;
    int i;
    t_list  *temp;
    
    stack_b_len = ft_lstsize(stacks->b);
    temp = stacks->b;
    i = 0;
    while (i < stack_b_len)
    {  
        temp = stacks->b;
        total_moves_count = i ;
        ft_rotate_stack(&(temp));
        

        i++;
    }
}