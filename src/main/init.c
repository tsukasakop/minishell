/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:27:02 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/18 17:09:56 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Do anything before starting shell such as:
 *   setup signal handler
 *   setup function do on exit
 *   ...
 *
 * Returns: false if any unexpected result will happen, otherwise true
 */
bool	init(char **envp)
{
	rl_outstream = stderr;
	set_handlers_for_process();
	ft_atexit(ft_g_mmfree);
	ft_initenv(envp);
	return (true);
}
