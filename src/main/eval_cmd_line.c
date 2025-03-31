/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_cmd_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:33:40 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/27 19:37:13 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Execute text get from prompt
 * 		(if not implement bonus, it do nothing but eval_pipe)
 *
 * const char *cmd_line: string to do as a command
 * char **envp: string of envp
 */
unsigned char	eval_cmd_line(char **envp)
{
	char			*input;
	unsigned char	status;

	set_error_type(NOERR);
	input = get_input();
	if (!input)
		return (get_exit_status_from_err_type(get_error_type()));
	status = eval_pipe(input, envp);
	if (g_signal)
		status = 128 + g_signal;
	return (status);
}
