/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:32:09 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/07 22:54:21 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * wait for finshing child processes, and get exit status
 * TODO: update g_signal when child processes catch signal
 */
unsigned char	wait_status(void)
{
	int	status;

	while (wait(&status) != -1)
		;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		g_signal = WTERMSIG(status);
	return (1);
}
