/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:27:40 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/26 12:39:51 by miyuu            ###   ########.fr       */
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
 *
 */
void	resolve_redirects(int stdio[2], t_redirect *redir)
{
	t_redirect	*cur;

	cur = redir;
	dup2(stdio[0], STDIN_FILENO);
	dup2(stdio[1], STDOUT_FILENO);
	while (cur)
	{
		connect_redirects_path(cur);
		cur = cur->next;
	}
	close_fds_no_stdio(stdio, 2);
	free_redirects(redir);
}
