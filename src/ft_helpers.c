/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:57:51 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/01 00:26:36 by bamrouch         ###   ########.fr       */
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

int	ft_abs(int i)
{
	if ( i < 0)
		return i * -1;
	return i;
}

void	ft_set_best_b_push(int value, int *res,int *temp)
{
	int res_score;
	int temp_score;
	
	res_score = ft_abs(res[1]) + ft_abs(res[2]);
	temp_score = ft_abs(temp[1]) + ft_abs(temp[2]);
	if (temp_score < res_score)
	{
		res[0] = value;
		res[1] = temp[1];
		res[2] = temp[2];
	}
}
