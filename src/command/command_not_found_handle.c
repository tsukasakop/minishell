/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_not_found_handle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:35:27 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/17 18:42:23 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:command_not_found_handle
 * ----------------------------
 * command_not_found error output.
 * Returns exit status 127.
 */
int	command_not_found_handle(char *cmd)
{
	char	*error_msg;

	error_msg = ": command not found\n";
	write(2, SHELL_NAME, ft_strlen(SHELL_NAME));
	write(2, cmd, ft_strlen(cmd));
	write(2, error_msg, ft_strlen(error_msg));
	return (127);
}
