/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:32:09 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/22 15:08:42 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * wait for finshing child processes, and get exit status
 */
unsigned char	wait_status(void)
{
	int	status;

	while (wait(&status) != -1)
		;
	// TODO: update g_signal when child processes catch signal
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		g_signal = WTERMSIG(status);
	return (1);
}
