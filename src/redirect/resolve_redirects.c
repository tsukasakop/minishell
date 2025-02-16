/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:27:40 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/16 20:17:17 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Set redirects to stdio or others on simple command
 *
 * int stdio[2]: fds to be redirect from stdin(0), and stdout(1)
 * t_redirect *red: object to open and redirect
 */
void	resolve_redirects(int stdio[2], t_redirect *red)
{
	dup2(stdio[0], STDIN_FILENO);
	dup2(stdio[1], STDOUT_FILENO);
	close_fds_safely(stdio, 2);
	// TODO: do redirect on red
	free_redirects(red);
}
