/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:33:40 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/26 16:09:04 by miyuu            ###   ########.fr       */
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
unsigned char	eval_cmd_line(const char *cmd_line, char **envp)
{
	unsigned char	status;

	status = eval_pipe(cmd_line, envp);
	return (status);
}
