/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:33:38 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/14 19:39:19 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

t_boolean	ft_swap_commands_no_print(t_stack_group *stacks, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
	{
		ft_swap_stack_top_elements(&(stacks->a));
		return (TRUE);
	}
	else if (!ft_strncmp(cmd, "sb\n", 3))
	{
		ft_swap_stack_top_elements(&(stacks->b));
		return (TRUE);
	}
	else if (!ft_strncmp(cmd, "ss\n", 3))
	{
		ft_swap_stack_top_elements(&(stacks->a));
		ft_swap_stack_top_elements(&(stacks->b));
		return (TRUE);
	}
	return (FALSE);
}

t_boolean	ft_push_commands_no_print(t_stack_group *stacks, char *cmd)
{
	if (!ft_strncmp(cmd, "pa\n", 3))
	{
		ft_push_element_to_stack(&(stacks->a), &(stacks->b));
		return (TRUE);
	}
	else if (!ft_strncmp(cmd, "pb\n", 3))
	{
		ft_push_element_to_stack(&(stacks->b), &(stacks->a));
		return (TRUE);
	}
	return (FALSE);
}

t_boolean	ft_rotate_commands_no_print(t_stack_group *stacks, char *cmd)
{
	if (!ft_strncmp(cmd, "ra\n", 3))
	{
		ft_rotate_stack(&(stacks->a));
		return (TRUE);
	}
	else if (!ft_strncmp(cmd, "rb\n", 3))
	{
		ft_rotate_stack(&(stacks->b));
		return (TRUE);
	}
	else if (!ft_strncmp(cmd, "rr\n", 3))
	{
		ft_rotate_stack(&(stacks->a));
		ft_rotate_stack(&(stacks->b));
		return (TRUE);
	}
	return (FALSE);
}

t_boolean	ft_reverse_rotate_commands_no_print(t_stack_group *stacks,
		char *cmd)
{
	if (!ft_strncmp(cmd, "rra\n", 4))
	{
		ft_reverse_rotate_stack(&(stacks->a));
		return (TRUE);
	}
	else if (!ft_strncmp(cmd, "rrb\n", 4))
	{
		ft_reverse_rotate_stack(&(stacks->b));
		return (TRUE);
	}
	else if (!ft_strncmp(cmd, "rrr\n", 4))
	{
		ft_reverse_rotate_stack(&(stacks->a));
		ft_reverse_rotate_stack(&(stacks->b));
		return (TRUE);
	}
	return (FALSE);
}

t_boolean	ft_handle_commands_bonus(t_stack_group *stacks, char *cmd)
{
	if (!cmd)
		return (FALSE);
	if (ft_swap_commands_no_print(stacks, cmd))
		return (TRUE);
	else if (ft_push_commands_no_print(stacks, cmd))
		return (TRUE);
	else if (ft_rotate_commands_no_print(stacks, cmd))
		return (TRUE);
	else if (ft_reverse_rotate_commands_no_print(stacks, cmd))
		return (TRUE);
	return (FALSE);
}
