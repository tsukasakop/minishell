/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:19:38 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/17 02:30:57 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_ft_unistd.h>
#include <ft_stdlib.h>

// void	command_not_found_handle(char *cmd)
// {
// 	char	*error_msg;

// 	error_msg = ": command not found\n";
// 	write(2, cmd, ft_strlen(cmd));
// 	write(2, error_msg, ft_strlen(error_msg));
// 	exit(127);
// }

// void	execute_cmd(char **cmd, char **envp)
// {
// 	if (access(cmd[0], F_OK) == -1)
// 	{
// 		if (ft_strchr (cmd[0], '/') == NULL)
// 			command_not_found_handle(cmd[0]);
// 		else
// 			perror_exit(cmd[0], 127);
// 	}
// 	if (execve(cmd[0], cmd, envp) < 0)
// 		perror_exit(cmd[0], 126);
// }

static const char	*find_path(const char *name)
{
	char	*tmp;
	char	*path;
	char	**dirs;

	if (ft_getenv("PATH") == NULL)
		return (NULL);
	dirs = ft_split(ft_getenv("PATH"), ':');
	while (dirs && *dirs)
	{
		tmp = ft_strjoin(*dirs, "/");
		path = ft_strjoin(tmp, name);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			while (*dirs)
				free(*dirs++);
			return ((const char *)path);
		}
		free(path);
		free(*dirs);
		dirs++;
	}
	return (NULL);
}

int	ft_execvp(const char *path, char *const argv[])
{
	const char	*abs_path;
	int			ret;

	if (ft_strchr(path, '/') != NULL)
		return (execve(path, argv, NULL));
	abs_path = find_path(path);
	if (abs_path == NULL)
		return (127);
	ret = execve(abs_path, argv, NULL);
	free((void *)abs_path);
	return (ret);
}
