/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:26:37 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/08 19:41:34 by bamrouch         ###   ########.fr       */
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
		ft_rotate_stack
		stack_moves[1]--;
		stack_moves[2]--;
	}
	while (stack_moves[1] < 0 && stack_moves[2] < 0)
	{
		ft_handle_commands(stacks, "rrr");
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
	ft_rotate_stacks_simult(stacks,cpy_moves);
	ft_rotate_stack(&(stacks->a),&(cpy_moves[1]));
	ft_rotate_stack_b(&(stacks->b),&(cpy_moves[2]));
	ft_handle_commands(stacks,"pa");
	
	return (ft_abs(moves[1]) + ft_abs(moves[2]) + 1);
}

int	**ft_stack_iteration_best_path(t_stack_group *stacks,t_list *temp_stack_b,int *moves_count)
{
    int temp_stack_b_len;
    int **best_moves_path;
	int	*best_push;
    int i;

    temp_stack_b_len = ft_lstsize(temp_stack_b);
    best_moves_path = ft_calloc(temp_stack_b_len ,sizeof(int *));
    if (!best_moves_path)
        ft_exit_process_with_error(stacks);
    i = 0;
    while (temp_stack_b_len--)
    {
		best_push = malloc(sizeof(int) * 3);
		if (!best_push)
		{
			ft_free_best_moves_path(&best_moves_path, i);
			ft_exit_process_with_error(stacks);
		}
        ft_find_best_push(stacks,best_push);
		*moves_count += ft_fix_path(stacks,best_push);
		best_moves_path[i++] = best_push;      
    }
	*moves_count += ft_abs(ft_fix_stack_hiearchy(stacks));
	return best_moves_path;
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

void	ft_free_stack_group(t_stack_group *stacks)
{
	ft_lstclear(&stacks->a,free);
	ft_lstclear(&stacks->b,free);
	free(stacks);
}



int ft_find_best_push_path(t_stack_group *stacks)
{
    int stack_b_len;
    int **path[2];
    int total_moves_count[2];
    int i[2];
    t_stack_group  *temp;
    
    stack_b_len = ft_lstsize(stacks->b);
    i[0] = 1;
	temp = ft_copy_stack_group(stacks);
	total_moves_count[0] = 0;
	path[0] = ft_stack_iteration_best_path(temp,temp->b,&(total_moves_count[0]));
    while (i[0] < stack_b_len)
    {  
		ft_free_stack_group(temp);
		temp = ft_copy_stack_group(stacks);
		total_moves_count[1] = i[0];
		i[1] = i[0]++;
		while (i[1]-- > 0)
        	ft_rotate_stack(&(temp->b));
		path[1] = ft_stack_iteration_best_path(temp, temp->b,&(total_moves_count[1]));
		if (total_moves_count[1] < total_moves_count[0])
		{
			ft_free_best_moves_path(&(path[0]),stack_b_len);
			path[0] = path[1];
			total_moves_count[0] = total_moves_count[1];
		}
		else
			ft_free_best_moves_path(&(path[1]),stack_b_len);
    }
	ft_free_stack_group(temp);
	return total_moves_count[0];
}