/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:17:03 by bamrouch          #+#    #+#             */
/*   Updated: 2022/12/28 23:57:31 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_new_sub_lis(int ***lis, int sub_list_len, int value)
{
	int	*new_sub_lis;
	int	**new_lis;
	int	i;

	new_lis = malloc(((*lis)[0][0] + 1) * sizeof(int *));
	if (!new_lis)
		return ft_free_lis(lis);
	i = -1;
	while (++i < (*lis)[0][0])
		new_lis[i] = (*lis)[i];
	free(*lis);
	new_lis[0][0]++;
	new_sub_lis = malloc((sub_list_len + 1) * sizeof(int));
	if (!new_sub_lis)
		return	ft_free_lis(lis);
	i = -1;
	while (++i < sub_list_len)
		new_sub_lis[i] = new_lis[new_lis[0][0] - 2][i];
	new_lis[new_lis[0][0] - 1] = new_sub_lis;
	new_sub_lis[sub_list_len] = value;
	new_sub_lis[0]++;
	*lis = new_lis;
}

void	ft_modify_lis(int ***lis, int index, int value)
{
	int	sub_list_len;

	sub_list_len = (*lis)[index - 1][0];
	if (index == (*lis)[0][0])
		ft_push_new_sub_lis(lis, sub_list_len, value);
	else if ((*lis)[index - 1][sub_list_len - 1] > value)
		(*lis)[index - 1][sub_list_len - 1] = value;
}

t_boolean	ft_is_smallest_lis_element(int ***lis, int value)
{
	int	i;
	int	sub_lis_len;

	// If smallest element in lis end elements create a new lis with len 1;
	i = 1;
	while (i < (*lis)[0][0])
	{
		sub_lis_len = (*lis)[i][0];
		if (value > (*lis)[i++][sub_lis_len - 1])
			return (FALSE);
	}
	ft_modify_lis(lis,2,value);
	ft_printf("case 1 smallest === %d\n",value);
	return (TRUE);
}

t_boolean	ft_is_largest_lis_element(int ***lis, int value)
{
	int	i;
	int	sub_lis_len;

	i = 1;
	while (i < (*lis)[0][0])
	{
		sub_lis_len = (*lis)[i][0];
		if (value < (*lis)[i][sub_lis_len - 1])
		{
			// if not biggest lis end element replace with the one smaller than it
			ft_modify_lis(lis, i, value);
			ft_printf(" case 3 in the middle ==== %d \n",value);
			return (FALSE);
		}
		i++;
	}
	// If biggest lis end element add it to the longest existing lis
	ft_modify_lis(lis, (*lis)[0][0], value);
	ft_printf("case 2 the biggest element === %d \n",value);
	return (TRUE);
}



int	*ft_find_lis(t_list *stack_a)
{
	int temp;
	int **lis;
	int i;
	int j;

	lis = malloc(2 * sizeof(int *));
	lis[0] = malloc(1 * sizeof(int));
	lis[0][0] = 2;
	lis[1] = malloc(2 * sizeof(int));
    lis[1][0] = 2;
	lis[1][1] = *((int *)stack_a->content);
	stack_a = stack_a->next;
	while (stack_a && lis)
	{
		temp = *((int *)stack_a->content);
		if (!ft_is_smallest_lis_element(&lis, temp))
			ft_is_largest_lis_element(&lis, temp);
		stack_a = stack_a->next;
	}
	i = 0;
	while (++i < lis[0][0])
	{
		ft_printf("longest increasing subsequence %d ------  \n",i);
		j = 0;
		while(++j < lis[i][0])
			ft_printf("%d \n",lis[i][j]);
	}
    return lis[lis[0][0] - 1];
}