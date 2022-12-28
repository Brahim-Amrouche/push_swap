/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:35:56 by bamrouch          #+#    #+#             */
/*   Updated: 2022/12/28 23:48:54 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_stack_group *stacks)
{
	t_list *temp;

	ft_printf("Stack a ======= \n");
	temp = stacks->a;
	while (temp)
	{
		ft_printf("%d \n", *((int *) temp->content));
		temp = temp->next;
	}
	ft_printf("Stack b ======= \n");
	temp = stacks->b;
	while (temp)
	{
		ft_printf("%d \n", *((int *) temp->content));
		temp = temp->next;
	}
	ft_printf("End of printing Stacks \n");
}

int	main(int argc, char *argv[])
{
	t_stack_group	stacks;

	ft_bzero(&stacks, sizeof(t_stack_group));
	ft_init_stack_group(&(stacks.a), argc, argv);
	ft_print_stacks(&stacks);
	//commands
	ft_find_lis((&stacks)->a);
	//commands
	return (0);
}
