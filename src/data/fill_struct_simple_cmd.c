/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_simple_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:33:55 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/26 16:09:54 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:fill_struct_simple_cmd
 * ----------------------------
 * Parses const char *cmd_line and returns the head of the simple_cmd list.
 *
 * ToDO:norminetteエラー
 */
t_simple_cmd	*fill_struct_simple_cmd(const char *cmd_line)
{
	char			**pipeline;
	t_simple_cmd	*head;
	t_simple_cmd	*cur;
	t_simple_cmd	*new_s_cmd;
	int				i;

	pipeline = pipe2simple_cmds(cmd_line);
	if (!pipeline)
		return (NULL);
	i = 0;
	head = NULL;
	cur = NULL;
	while (pipeline[i])
	{
		new_s_cmd = load_simple_cmd(ft_split(pipeline[i], ' '));
		if (!new_s_cmd)
		{
			free_simple_cmds(head);
			free(pipeline);
			return (NULL);
		}
		if (!head)
			head = new_s_cmd;
		else
			cur->next = new_s_cmd;
		cur = new_s_cmd;
		i++;
	}
	free(pipeline);
	return (head);
}
