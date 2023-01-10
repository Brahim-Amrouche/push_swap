/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:36:06 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/10 19:56: by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_boolean	ft_stack_has_duplication(t_list **stack, int content)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		if (*((int *)(temp->content)) == content)
			return (TRUE);
		temp = temp->next;
	}
	return (FALSE);
}

t_boolean	ft_push_to_stack(t_list **stack, int content)
{
	t_list	*new;
	int		*m_content;

	if (ft_stack_has_duplication(stack, content))
		return (FALSE);
	m_content = malloc(sizeof(int));
	if (!m_content)
		return (FALSE);
	*m_content = content;
	new = ft_lstnew(m_content);
	if (!new)
	{
		free(m_content);
		return (FALSE);
	}
	ft_lstadd_back(stack, new);
	return (TRUE);
}

t_boolean	ft_str_is_integer(const char *str, long *res)
{
	int		i;
	long	temp;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (FALSE);
	while (str[i] && !ft_is_space(str[i]))
		if (!ft_isdigit(str[i++]))
			return (FALSE);
	temp = ft_atoi(str);
	if (temp > INT_MAX || temp < INT_MIN)
		return (FALSE);
	*res = temp;
	return (TRUE);
}

t_boolean	ft_parse_input(t_list **stack, int input_len, char *input_content[])
{
	int		i;
	size_t	j;
	long	temp;

	i = 1;
	while (i < input_len)
	{
		j = 0;
		while (input_content[i][j])
		{
			while (input_content[i][j] && ft_is_space(input_content[i][j]))
				j++;
			if (!input_content[i][j])
				break ;
			if (!ft_str_is_integer(&(input_content[i][j]), &temp))
				return (FALSE);
			if (!ft_push_to_stack(stack, temp))
				return (FALSE);
			while (input_content[i][j] && !ft_is_space(input_content[i][j]))
				j++;
		}
		i++;
	}
	return (TRUE);
}

void	ft_init_stack_group(t_stack_group *stacks, int input_len,
		char *input_content[])
{
	if (input_len == 1)
		exit(0);
	if (!ft_parse_input(&(stacks->a), input_len, input_content))
		ft_exit_process_with_error(stacks);
}
