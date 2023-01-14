/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:46:11 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/14 02:07:05 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

t_boolean	ft_line_is_valid_push_swap_command(char *line)
{
	if (ft_strncmp(line, "sa\n", 3) || ft_strncmp(line, "sb\n", 3)
		|| ft_strncmp(line, "ss\n", 3))
		return (TRUE);
	else if (ft_strncmp(line, "pa\n", 3) || ft_strncmp(line, "pb\n", 3))
		return (TRUE);
	else if (ft_strncmp(line, "ra\n", 3) || ft_strncmp(line, "rb\n", 3)
		|| ft_strncmp(line, "rr\n", 3))
		return (TRUE);
	else if (ft_strncmp(line, "rra\n", 4) || ft_strncmp(line, "rrb\n", 4)
		|| ft_strncmp(line, "rrr\n", 4))
		return (TRUE);
	return (FALSE);
}

// both strings should be malloced;
char	*ft_strjoin_with_free(char *s1, char *s2)
{
	char	*res;

	if (!s2)
		return (s1);
	res = ft_strjoin(s1, s2);
	free(s2);
	free(s1);
	return (res);
}

char	*ft_read_standard_input(void)
{
	char	*res;
	char	*line;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	line = get_next_line(0);
	if (!line)
		return (res);
	while (line)
	{
		res = ft_strjoin_with_free(res, line);
		if (!res)
			return (NULL);
		line = get_next_line(0);
	}
	return (res);
}

void	ft_sort_stack(t_stack_group *stacks, char *commands_str)
{
	char	*temp_command;

	temp_command = ft_strchr(commands_str, '\n');
	while (temp_command)
	{
		if (!ft_line_is_valid_push_swap_command(temp_command))
		{
			free(commands_str);
			ft_exit_process_with_error(stacks);
		}
		ft_handle_commands(stacks, "something something");
	}
}

int	main(int argc, char *argv[])
{
	t_stack_group	stacks;
	char			*commands_str;
	char			*temp_command;

	ft_bzero(&stacks, sizeof(stacks));
	ft_init_stack_group(&stacks, argc, argv);
	commands_str = ft_read_standard_input();
	if (!commands_str)
		ft_exit_process_with_error(&stacks);
}
