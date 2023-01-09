/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:59:02 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/09 16:29:34 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_process_with_error(t_stack_group *stacks)
{
	ft_printf("Error\n");
	ft_lstclear(&(stacks->a),free);
	ft_lstclear(&(stacks->b),free);
	exit(1);
}

int	ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

void	ft_print_stacks(t_stack_group *stacks)
{
	t_list	*temp;

	ft_printf("Stack a ======= \n");
	temp = stacks->a;
	while (temp)
	{
		ft_printf("%d \n", *((int *)temp->content));
		temp = temp->next;
	}
	ft_printf("Stack b ======= \n");
	temp = stacks->b;
	while (temp)
	{
		ft_printf("%d \n", *((int *)temp->content));
		temp = temp->next;
	}
	ft_printf("End of printing Stacks \n");
}

void	ft_find_array_limits(int *array, int limits[2])
{
	int	pos;

	limits[1] = 1;
	limits[0] = 1;
	pos = 2;
	while (pos < array[0])
	{
		if (array[pos] > array[limits[1]])
			limits[1] = pos;
		else if (array[pos] < array[limits[0]])
			limits[0] = pos;
		pos++;
	}
}
