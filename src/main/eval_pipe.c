/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:33:15 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/25 19:59:58 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdio.h>

void	print_commands(const t_simple_cmd *cmds)
{
	int i = 0;

	while (cmds)
	{
		printf("Command[%d]:\n", i++);
		printf("  words:");
		for (int j = 0; cmds->words[j]; j++)
			printf(" %s,", cmds->words[j]);
		printf("\n");
		t_redirect *red = cmds->reds;
		while (red)
		{
			printf("  Redirect: type=%d, path=%s\n", red->redir_type, red->path);
			red = red->next;
		}
		cmds = cmds->next;
	}
}
/*
 * Function:
 * ----------------------------
 * Execute pipeline
 *
 * const char* textt: string of pipeline
 * char **envp: string of envp
 */
unsigned char	eval_pipe(const char *text, char **envp)
{
	const t_simple_cmd	*scmd_list;
	t_simple_cmd		*cur;
	int					stdio_fd[2];
	int					next_in_fd;

	//ToDo:fill_struct_simple_cmdにheredocも渡す。fill_struct_simple_cmd(text, &scmd_list, &hd_list);になる
	scmd_list = fill_struct_simple_cmd(text);
	print_commands(scmd_list);
	//ToDo:ヒアドクの入力を取得する処理を追加
	stdio_fd[0] = STDIN_FILENO;
	stdio_fd[1] = STDOUT_FILENO;
	next_in_fd = STDIN_FILENO;
	cur = (t_simple_cmd *)scmd_list;
	while (cur)
	{
		if (!iterate_pipefd(cur == scmd_list, cur->next == NULL, &stdio_fd, \
			&next_in_fd))
		{
			// TODO: consider about pipe failure case
			free_simple_cmds((t_simple_cmd *)scmd_list);
			close_fds_no_stdio(stdio_fd, 2);
			close_fds_no_stdio(&next_in_fd, 1);
		}
		execute_simple_cmd(cur, stdio_fd, next_in_fd, envp);
		cur = cur->next;
	}
	free_simple_cmds((t_simple_cmd *)cur);
	close_fds_no_stdio((int [3]){stdio_fd[0], stdio_fd[1], next_in_fd}, 3);
	return (wait_status());
}
