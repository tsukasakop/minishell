/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_simple_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:33:55 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/22 22:34:16 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:fill_struct_simple_cmd
 * ----------------------------
 * Parses const char *text and returns the head of the simple_cmd list.
 *
 * ToDO:norminetteエラー
 */
t_simple_cmd	*fill_struct_simple_cmd(const char *text)
{
	char			**cmds_text;
	t_simple_cmd	*head;
	t_simple_cmd	*current;
	t_simple_cmd	*new_cmd;
	int				i;

	cmds_text = pipe2simple_cmds(text);
	if (!cmds_text)
		return (NULL);
	i = 0;
	head = NULL;
	current = NULL;
	while (cmds_text[i])
	{
		new_cmd = load_simple_cmd(ft_split(cmds_text[i], ' '));
		if (!new_cmd)
		{
			free_simple_cmds(head);
			free(cmds_text);
			return (NULL);
		}
		if (!head)
			head = new_cmd;
		else
			current->next = new_cmd;
		current = new_cmd;
		i++;
	}
	free(cmds_text);
	return (head);
}
