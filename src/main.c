/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:35:56 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/11 19:26:26 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack_group	stacks;

	ft_bzero(&stacks, sizeof(t_stack_group));
	ft_init_stack_group(&stacks, argc, argv);
	ft_find_stack_solution(&stacks);
	ft_free_stack_group(&stacks);
	return (0);
}
