/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:50:29 by bamrouch          #+#    #+#             */
/*   Updated: 2022/12/20 00:33:09 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_boolean	ft_swap_commands(t_stack_group *stacks, char *cmd, size_t cmd_len)
{
	if (!ft_strncmp(cmd, "sa", cmd_len))
	{
		ft_swap_stack_top_elements(&(stacks->a));
		ft_printf("sa\n");
		return (TRUE);
	}
	else if (!ft_strncmp(cmd, "sb", cmd_len))
	{
		ft_swap_stack_top_elements(&(stacks->b));
		ft_printf("sb\n");
		return (TRUE);
	}
	else if (!ft_strncmp(cmd, "ss", cmd_len))
	{
		ft_swap_stack_top_elements(&(stacks->a));
		ft_swap_stack_top_elements(&(stacks->b));
		ft_printf("ss\n");
		return (TRUE);
	}
	return (FALSE);
}

t_boolean	ft_push_commands(t_stack_group *stacks, char *cmd, size_t cmd_len)
{
	if (!ft_strncmp(cmd, "pa", cmd_len))
	{
		ft_push_element_to_stack(&(stacks->a), &(stacks->b));
		ft_printf("pa\n");
		return (TRUE);
	}
	else if (!ft_strncmp(cmd, "pb", cmd_len))
	{
		ft_push_element_to_stack(&(stacks->b), &(stacks->a));
		ft_printf("pb\n");
		return (TRUE);
	}
	return (FALSE);
}

t_boolean	ft_rotate_commands(t_stack_group *stacks, char *cmd, size_t cmd_len)
{
	if (!ft_strncmp(cmd, "ra", cmd_len))
	{
		ft_rotate_stack(&(stacks->a));
		ft_printf("ra\n");
		return (TRUE);
	}
	else if (!ft_strncmp(cmd, "rb", cmd_len))
	{
		ft_rotate_stack(&(stacks->b));
		ft_printf("rb\n");
		return (TRUE);
	}
	else if (!ft_strncmp(cmd, "rr", cmd_len))
	{
		ft_rotate_stack(&(stacks->a));
		ft_rotate_stack(&(stacks->b));
		ft_printf("rr\n");
		return (TRUE);
	}
	return (FALSE);
}

t_boolean	ft_reverse_rotate_commands(t_stack_group *stacks, char *cmd,
		size_t cmd_len)
{
	if (!ft_strncmp(cmd, "rra", cmd_len))
	{
		ft_reverse_rotate_stack(&(stacks->a));
		ft_printf("rra\n");
		return (TRUE);
	}
	else if (!ft_strncmp(cmd, "rrb", cmd_len))
	{
		ft_reverse_rotate_stack(&(stacks->b));
		ft_printf("rrb\n");
		return (TRUE);
	}
	else if (!ft_strncmp(cmd, "rrr", cmd_len))
	{
		ft_reverse_rotate_stack(&(stacks->a));
		ft_reverse_rotate_stack(&(stacks->b));
		ft_printf("rrr\n");
		return (TRUE);
	}
	return (FALSE);
}

void	ft_handle_commands(t_stack_group *stacks, char *cmd)
{
	size_t	cmd_len;

	cmd_len = ft_strlen(cmd);
	if (ft_swap_commands(stacks, cmd, cmd_len))
		return ;
	else if (ft_push_commands(stacks, cmd, cmd_len))
		return ;
	else if (ft_rotate_commands(stacks, cmd, cmd_len))
		return ;
	else if (ft_reverse_rotate_commands(stacks, cmd, cmd_len))
		return ;
}
