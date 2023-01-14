/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:57:51 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/13 21:48:35 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lis(int ***lis)
{
	int	i;

	i = (*lis)[0][0];
	while (i > 0)
		free((*lis)[--i]);
	free(*lis);
	*lis = NULL;
}

int	*ft_return_lis_result(int ***lis)
{
	int	*res;

	res = (*lis)[(*lis)[0][0] - 1];
	(*lis)[0][0]--;
	ft_free_lis(lis);
	return (res);
}

int	*ft_copy_stack_to_list(t_list *stack)
{
	int	i;
	int	*res;

	res = malloc((ft_lstsize(stack) + 1) * sizeof(int));
	if (!res)
		return (NULL);
	i = 1;
	while (stack)
	{
		res[i++] = *(int *)stack->content;
		stack = stack->next;
	}
	res[0] = i;
	return (res);
}
