/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:42:20 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/03 22:54:52 by bamrouch         ###   ########.fr       */
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
	int limits[2];
	int *stack_list;

	stack_list = ft_copy_stack_to_list(stack_a);
	if (!stack_a)
	{
		ft_printf("Error\n");
		exit(1);
	}
	
	if (stack_list[1] > stack_list[2])
	{
		limits[1] = 1;
		limits[0] = 2;
	}
	else
	{
		limits[1] = 2;
		limits[0] = 1;
	}
	pos = 3;
	while (pos < stack_list[0])
	{
		if (stack_list[pos] > stack_list[limits[1]])
			limits[1] = pos;
		else if (stack_list[pos] < stack_list[limits[0]])
			limits[0] = pos;
		pos++;
	}
	pos = 1;
	while (pos < stack_list[0] - 1)
	{
		if (stack_list[pos] < value && stack_list[pos + 1] > value)
			break;
		pos++;
	}
	if (value < stack_list[limits[0]] || value > stack_list[limits[1]])
		pos = limits[1];
	pos = pos % (stack_list[0] - 1);
	if (pos > (stack_list[0] - 1) - pos)
		pos = pos - (stack_list[0] - 1);
	free(stack_list);
	return pos;
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

void    ft_sort_stack(t_stack_group *stacks)
{
    int best_push[3];

    while (stacks->b)
    {
        ft_find_best_push(stacks,best_push);
        ft_printf("best push value : %d;moves on A : %d;moves on B : %d\n",best_push[0],best_push[1],best_push[2]);
        ft_print_stacks(stacks);
        while (best_push[1] > 0 && best_push[2] > 0)
        {
            ft_handle_commands(stacks,"rr");
            best_push[1]--;
            best_push[2]--;   
        }
        while (best_push[1] < 0 && best_push[2] < 0)
        {
            ft_handle_commands(stacks,"rrr");
            best_push[1]++;
            best_push[2]++;
        }
        while(best_push[1] > 0)
        {
            ft_handle_commands(stacks,"ra");
            best_push[1]--;
        }
        while (best_push[1] < 0)
        {
            ft_handle_commands(stacks,"rra");
            best_push[1]++;
        }
        while(best_push[2] > 0)
        {
            ft_handle_commands(stacks,"rb");
            best_push[2]--;
        }
        while(best_push[2] < 0)
        {
            ft_handle_commands(stacks,"rrb");
            best_push[2]++;   
        }
        ft_handle_commands(stacks,"pa");
    }
}

void	ft_find_stack_solution(t_stack_group *stacks, int *lis)
{
	int  best_push[3];
	ft_push_non_lis_to_b(stacks, lis);
	// ft_handle_commands(stacks,"rr");
	ft_handle_commands(stacks,"pa");
	ft_handle_commands(stacks,"pa");
	// ft_handle_commands(stacks,"ra");
	// ft_handle_commands(stacks,"pa");
    ft_find_best_push(stacks,best_push);
	ft_printf("best push value : %d;moves on A : %d;moves on B : %d\n",best_push[0],best_push[1],best_push[2]);
	ft_print_stacks(stacks);
	// now after finding the optiomal push it's time to apply it
}