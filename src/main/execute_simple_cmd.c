/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:30:10 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/17 03:35:00 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * execute simple command
 *
 * const t_simple_cmd: is raw simple command
 * int stdio_fd[2]: are fds to be redirect from stdio
 * int next_in_fd: is fd to be close on child process
 * char **envp: string if envp
 * TODO; bool	execute_simple_cmd(t_simple_cmd *scmd_list, t_execute_session session)
 */

void	perror_exit_status(char *msg, int status)
{
	write(2, SHELL_NAME, ft_strlen(SHELL_NAME));
	perror(msg);
	ft_exit (status);
}


void	command_not_found_handle(char *cmd)
{
	char	*error_msg;

	error_msg = ": command not found\n";
	write(2, SHELL_NAME, ft_strlen(SHELL_NAME));
	write(2, cmd, ft_strlen(cmd));
	write(2, error_msg, ft_strlen(error_msg));
	ft_exit(127);
}

 #include <sys/stat.h>
int is_directory(const char *path) {
    struct stat path_stat;
    if (stat(path, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
        return 1; // ディレクトリなら 1 を返す
    return 0; // それ以外は 0
}

bool	execute_simple_cmd(const t_simple_cmd *scmd_list, int stdio_fd[2],
		int next_in_fd, char **envp)
{
	const char	*path;
	int			chpid;

	chpid = fork();
	if (chpid)
	{
		free_redirects(scmd_list->redir);
		free_ecmds(scmd_list->ecmds);
		return (chpid != -1);
	}
	set_handlers_default();
	close_fds_no_stdio(&next_in_fd, 1);
	resolve_redirects(stdio_fd, scmd_list->redir);
	if (!scmd_list->ecmds[0])
		ft_exit(0);
	if (is_builtin(scmd_list->ecmds[0]))
		ft_exit(execute_builtin(scmd_list->ecmds, envp));
	path = get_path(scmd_list->ecmds[0]);

	if (ft_execvp(path, scmd_list->ecmds) == 127)
		command_not_found_handle((char *)path);
	else if (ft_strchr (path, '/') != NULL && access(path, F_OK) == -1)
		perror_exit_status((char *)path, 127);
	else if (is_directory(path))
		ft_fprintf(ft_stderr(), "bash: %s: Is a directory\n", path);
	else if (access(path, X_OK) == -1)
		perror_exit_status((char *)path, 126);
	else
		perror_exit_status((char *)path, 126);
	(void)envp;
	ft_exit(126);
	return (false);
}
