/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:32:09 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/18 14:32:56 by tkondo           ###   ########.fr       */
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
	//TODO: update g_signal when child processes catch signal
	if (WIFSIGNALED(status))
		g_signal = WTERMSIG(status);
	return (status);
}
