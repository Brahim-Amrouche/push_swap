/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:59:02 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/14 18:28:20 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack_group(t_stack_group *stacks)
{
	ft_lstclear(&(stacks->a), free);
	ft_lstclear(&(stacks->b), free);
}

void	ft_exit_process_with_error(t_stack_group *stacks)
{
	write(2, "Error\n", 6);
	ft_free_stack_group(stacks);
	exit(EXIT_FAILURE);
}

int	ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

t_boolean	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (TRUE);
	return (FALSE);
}
// void	ft_print_stacks(t_stack_group *stacks)
// {
// 	t_list	*temp;

// 	ft_printf("Stack a ======= \n");
// 	temp = stacks->a;
// 	while (temp)
// 	{
// 		ft_printf("%d \n", *((int *)temp->content));
// 		temp = temp->next;
// 	}
// 	ft_printf("Stack b ======= \n");
// 	temp = stacks->b;
// 	while (temp)
// 	{
// 		ft_printf("%d \n", *((int *)temp->content));
// 		temp = temp->next;
// 	}
// 	ft_printf("End of printing Stacks \n");
// }

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
