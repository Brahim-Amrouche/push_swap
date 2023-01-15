/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:46:11 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/15 19:06:25 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

t_boolean	ft_stack_is_sorted(t_stack_group *stacks)
{
	t_list	*temp;
	int		value;

	temp = stacks->a->next;
	value = *(int *)stacks->a->content;
	while (temp)
	{
		if (value > *(int *)temp->content)
			return (FALSE);
		value = *(int *)temp->content;
		temp = temp->next;
	}
	return (TRUE);
}

t_boolean	ft_sort_stack_with_commands(t_stack_group *stacks)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		if (!ft_handle_commands_bonus(stacks, command))
		{
			free(command);
			write(2, "Error\n", 6);
			return (FALSE);
		}
		free(command);
		command = get_next_line(0);
	}
	if (!(ft_lstsize(stacks->b) == 0 && ft_stack_is_sorted(stacks)))
	{
		ft_printf("KO\n");
		return (FALSE);
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_stack_group	stacks;

	ft_bzero(&stacks, sizeof(stacks));
	ft_init_stack_group(&stacks, argc, argv);
	if (!stacks.a)
		ft_exit_process_with_error(&stacks);
	if (ft_sort_stack_with_commands(&stacks))
		ft_printf("OK\n");
	ft_free_stack_group(&stacks);
	exit(EXIT_SUCCESS);
	return (0);
}
