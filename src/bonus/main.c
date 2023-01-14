/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:46:11 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/14 18:44:27 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

// t_boolean	ft_line_is_valid_push_swap_command(char *line)
// {
// 	if ( !ft_strncmp(line, "sa\n", 3) || !ft_strncmp(line, "sb\n", 3)  
// 		|| !ft_strncmp(line, "ss\n", 3))
// 		return (TRUE);
// 	else if (!ft_strncmp(line, "pa\n", 3) || !ft_strncmp(line, "pb\n", 3))
// 		return (TRUE);
// 	else if (!ft_strncmp(line, "ra\n", 3) || !ft_strncmp(line, "rb\n", 3)
// 		|| !ft_strncmp(line, "rr\n", 3))
// 		return (TRUE);
// 	else if (!ft_strncmp(line, "rra\n", 4) || !ft_strncmp(line, "rrb\n", 4)
// 		|| !ft_strncmp(line, "rrr\n", 4))
// 		return (TRUE);
// 	return (FALSE);
// }


// both strings should be malloced;
// char	*ft_strjoin_with_free(char *s1, char *s2)
// {
// 	char	*res;

// 	if (!s2)
// 		return (s1);
// 	res = ft_strjoin(s1, s2);
// 	free(s2);
// 	free(s1);
// 	return (res);
// }

// char	*ft_read_standard_input(void)
// {
// 	char	*res;
// 	char	*line;

// 	res = ft_strdup("");
// 	if (!res)
// 		return (NULL);
// 	line = get_next_line(0);
// 	if (!line)
// 		return (res);
// 	while (line)
// 	{
// 		res = ft_strjoin_with_free(res, line);
// 		if (!res)
// 			return (NULL);
// 		line = get_next_line(0);
// 	}
// 	return (res);
// }

t_boolean	ft_stack_is_sorted(t_stack_group *stacks)
{
	t_list *temp;
	int		value;

	temp = stacks->a->next;
	value = *(int *)stacks->a->content;
	while (temp)
	{
		if (value > *(int *)temp->content)
			return FALSE;
		value = *(int *)temp->content;
		temp = temp->next;
	}
	return TRUE;
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
			return FALSE;
		}
		free(command);
		command = get_next_line(0);
	}
	if (!(ft_lstsize(stacks->b) == 0 && ft_stack_is_sorted(stacks)))
	{
		ft_printf("KO\n");
		return FALSE;
	}
	return TRUE;
}


int	main(int argc, char *argv[])
{
	t_stack_group	stacks;

	ft_bzero(&stacks, sizeof(stacks));
	ft_init_stack_group(&stacks, argc, argv);
	if (ft_sort_stack_with_commands(&stacks))
		ft_printf("OK\n");
	ft_free_stack_group(&stacks);
}
