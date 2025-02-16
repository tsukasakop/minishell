/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:33:40 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/16 20:16:58 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Execute text get from prompt
 * 		(if not implement bonus, it do nothing but eval_pipe)
 *
 * const char *text: string to do as a command
 * char **envp: string of envp
 */
unsigned char	eval_text(const char *text, char **envp)
{
	unsigned char	status;

	status = eval_pipe(text, envp);
	return (status);
}
