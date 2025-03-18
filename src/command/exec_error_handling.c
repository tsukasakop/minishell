/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:35:11 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/18 00:28:58 by miyuu            ###   ########.fr       */
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
		return (command_not_found_handle(path));
	else if ((ft_getenv("PATH") == NULL || !(ft_strchr (path, '/') == NULL)) \
			&& access(path, F_OK) == -1)
		return (perror_return(path, 127));
	if (is_directory(path))
		ft_fprintf(ft_stderr(), "bash: %s: Is a directory\n", path);
	else
	{
		ft_fprintf(ft_stderr(), "bash: %s: ", path);
		ft_fprintf(ft_stderr(), "%s\n", strerror(err_num));
	}
	return (126);
}
