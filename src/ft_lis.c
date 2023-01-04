/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:17:03 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/04 19:40:41 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_new_sub_lis(int ***lis, int sub_list_len, int value)
{
	int		*new_sub_lis;
	int		**new_lis;
	ssize_t	i;

	new_lis = malloc(((*lis)[0][0] + 1) * sizeof(int *));
	if (!new_lis)
		return (ft_free_lis(lis));
	i = -1;
	while (++i < (*lis)[0][0])
		new_lis[i] = (*lis)[i];
	free(*lis);
	new_sub_lis = malloc((sub_list_len + 1) * sizeof(int));
	if (!new_sub_lis)
		return (ft_free_lis(lis));
	i = -1;
	while (++i < sub_list_len)
		new_sub_lis[i] = new_lis[new_lis[0][0] - 1][i];
	new_lis[0][0]++;
	new_lis[new_lis[0][0] - 1] = new_sub_lis;
	new_sub_lis[sub_list_len] = value;
	new_sub_lis[0]++;
	*lis = new_lis;
}

void	ft_modify_lis(int ***lis, int index, int value)
{
	ssize_t	sub_list_len;
	ssize_t	i;

	sub_list_len = (*lis)[index - 1][0];
	if (index == (*lis)[0][0])
		ft_push_new_sub_lis(lis, sub_list_len, value);
	else
	{
		i = 1;
		while (index > 1 && i < sub_list_len)
		{
			(*lis)[index][i] = (*lis)[index - 1][i];
			i++;
		}
		(*lis)[index][i] = value;
	}
}

t_boolean	ft_is_smallest_lis_element(int ***lis, int value)
{
	ssize_t	i;
	ssize_t	sub_lis_len;

	i = 1;
	while (i < (*lis)[0][0])
	{
		sub_lis_len = (*lis)[i][0];
		if (value > (*lis)[i++][sub_lis_len - 1])
			return (FALSE);
	}
	ft_modify_lis(lis, 1, value);
	return (TRUE);
}

t_boolean	ft_is_largest_lis_element(int ***lis, int value)
{
	ssize_t	i;
	ssize_t	sub_lis_len;

	i = 1;
	while (i < (*lis)[0][0])
	{
		sub_lis_len = (*lis)[i][0];
		if (value < (*lis)[i][sub_lis_len - 1])
		{
			ft_modify_lis(lis, i, value);
			return (FALSE);
		}
		i++;
	}
	ft_modify_lis(lis, (*lis)[0][0], value);
	return (TRUE);
}

int	*ft_find_lis(t_list *stack_a)
{
	int	temp;
	int	**lis;

	lis = malloc(2 * sizeof(int *));
	if (!lis)
		return (NULL);
	lis[0] = malloc(1 * sizeof(int));
	if (!lis[0])
	{
		free(lis);
		return (NULL);
	}
	lis[0][0] = 1;
	while (stack_a && lis)
	{
		temp = *((int *)stack_a->content);
		if (!ft_is_smallest_lis_element(&lis, temp))
			ft_is_largest_lis_element(&lis, temp);
		stack_a = stack_a->next;
	}
	if (lis)
		return (ft_return_lis_result(&lis));
	return (NULL);
}
