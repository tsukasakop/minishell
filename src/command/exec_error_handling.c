/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:35:11 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/07 01:42:36 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:exec_error_handling
 * ----------------------------
 * Error handling if command execution fails.
 * err_num: The errno set on execve failure.
 */
int	exec_error_handling(char *path, int status, int err_num)
{
	if (status == 127)
	{
		print_errmsg_with_str(EM_CMDNFND, path);
		return (127);
	}
	else if ((ft_getenv("PATH") == NULL || !(ft_strchr (path, '/') == NULL)) \
			&& access(path, F_OK) == -1)
	{
		print_errmsg_with_str(EM_SYSCALL, path);
		return (127);
	}
	if (is_directory(path))
		print_errmsg_with_str(EM_ISDIR, path);
	else
	{
		ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(err_num), STDERR_FILENO);
	}
	return (126);
}
