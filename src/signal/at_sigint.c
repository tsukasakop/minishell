/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_sigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:45:42 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/25 14:52:46 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  do when catch sigint on prompt
 */
void	at_sigint(int signal)
{
	(void)signal;
	g_signal = signal;
	set_exit_status(signal + 128);
	flush_prompt();
}
