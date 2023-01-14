/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:24:11 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/13 22:38:01 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_free_longest_lis(t_stack_group *stacks, t_list **cpy_stack_a,
	int *l_lis)
{
	ft_lstclear(cpy_stack_a, free);
	if (l_lis)
		free(l_lis);
	ft_exit_process_with_error(stacks);
}

void	ft_free_and_set_l_lis(int **lis, int *value)
{
	if (lis && *lis)
		free(*lis);
	*lis = value;
}

int	*ft_iterate_for_longest_lis(t_stack_group *stacks, t_list **cpy_stack_a)
{
	int	stack_a_len;
	int	*l_lis[2];

	stack_a_len = ft_lstsize(stacks->a);
	l_lis[1] = NULL;
	while (stack_a_len--)
	{
		l_lis[0] = ft_find_lis(*cpy_stack_a);
		if (!l_lis[0])
			ft_exit_free_longest_lis(stacks, cpy_stack_a, l_lis[1]);
		else if (!l_lis[1] || l_lis[0][0] > l_lis[1][0])
			ft_free_and_set_l_lis(&(l_lis[1]), l_lis[0]);
		else
			ft_free_and_set_l_lis(&(l_lis[0]), NULL);
		ft_rotate_stack(cpy_stack_a);
	}
	ft_lstclear(cpy_stack_a, free);
	return (l_lis[1]);
}

t_boolean	ft_handle_five_elements_stacks(t_stack_group *stacks, int **lis)
{
	int	stack_size;

	stack_size = ft_lstsize(stacks->a);
	if (stack_size <= 5 && (*lis)[0] - 1 != stack_size)
	{
		free(*lis);
		if (stack_size <= 3)
			ft_handle_commands(stacks, "sa");
		(*lis) = ft_find_longest_lis(stacks);
		if (!(*lis))
			ft_exit_process_with_error(stacks);
		ft_push_non_lis_to_b(stacks, (*lis), FALSE);
		return (TRUE);
	}
	return (FALSE);
}
