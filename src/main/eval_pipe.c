/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:33:15 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/27 22:45:08 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Execute pipeline
 *
 * const char* cmd_line: string of pipeline
 * char **envp: string of envp
 */
unsigned char	eval_pipe(const char *cmd_line, char **envp)
{
	const t_simple_cmd	*scmd_list;
	t_simple_cmd		*cur;
	int					stdio_fd[2];
	int					next_in_fd;

	//ToDo:fill_struct_simple_cmdにheredocも渡す。
	//fill_struct_simple_cmd(cmd_line, &scmd_list, &hd_list);になる
	scmd_list = pipe2scmd_list(cmd_line);
	//ToDo:ヒアドクの入力を取得する処理を追加
	stdio_fd[0] = STDIN_FILENO;
	stdio_fd[1] = STDOUT_FILENO;
	next_in_fd = STDIN_FILENO;
	cur = (t_simple_cmd *)scmd_list;
	if (cur->next == NULL && is_builtin(cur->ecmd[0]))
		return (execute_on_current_env(cur->ecmd, cur->redir, envp));
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
