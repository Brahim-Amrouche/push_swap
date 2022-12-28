/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:57:51 by bamrouch          #+#    #+#             */
/*   Updated: 2022/12/28 23:14:47 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_free_lis(int ***lis)
{
    int i;

    i = (*lis)[0][0];
    while (i > 0)
        free((*lis)[--i]);
    free(*lis);
    *lis = NULL;
}