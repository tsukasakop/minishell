/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_simple_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:33:55 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/03 02:51:14 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:fill_struct_simple_cmd
 * ----------------------------
 * Parses const char *cmd_line and returns the head of the simple_cmd list.
 *
 */
t_simple_cmd	*init_struct_simple_cmd(void)
{
	t_simple_cmd	*new_scmd;

	new_scmd = (t_simple_cmd *)malloc(sizeof(t_simple_cmd));
	if (!new_scmd)
		return (NULL);
	new_scmd->redir = NULL;
	new_scmd->next = NULL;
	new_scmd->ecmds = NULL;
	return (new_scmd);
}

t_simple_cmd	*process_simple_cmd(char *scmd_text, t_simple_cmd *head)
{
	t_simple_cmd	*new_scmd;
	char			**scmds;

	new_scmd = init_struct_simple_cmd();
	if (!new_scmd)
		return (NULL);
	scmds = ft_split(scmd_text, ' ');
	if (!scmds)
		return (free(new_scmd), NULL);
	if (!load_simple_cmd(new_scmd, scmds))
	{
		free(new_scmd);
		free_ecmds(scmds);
		free_simple_cmds(head);
		return (NULL);
	}
	free_ecmds(scmds);
	return (new_scmd);
}

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
		new_scmd = process_simple_cmd(scmd_texts[i], head);
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
