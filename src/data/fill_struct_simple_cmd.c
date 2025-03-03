/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_simple_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:33:55 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/27 16:28:52 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:fill_struct_simple_cmd
 * ----------------------------
 * Parses const char *cmd_line and returns the head of the simple_cmd list.
 *
 */
t_simple_cmd	*fill_struct_simple_cmd(char **scmd_texts)
{
	t_simple_cmd	*new_scmd;
	t_simple_cmd	*head;
	t_simple_cmd	*cur;
	int				i;

	i = 0;
	head = NULL;
	cur = NULL;
	while (scmd_texts[i])
	{
		new_scmd = load_simple_cmd(ft_split(scmd_texts[i], ' '));
		if (!new_scmd)
		{
			free_simple_cmds(head);
			free(scmd_texts);
			return (NULL);
		}
		if (!head)
			head = new_scmd;
		else
			cur->next = new_scmd;
		cur = new_scmd;
		i++;
	}
	return (head);
}
