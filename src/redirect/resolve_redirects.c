/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:27:40 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/14 03:46:08 by miyuu            ###   ########.fr       */
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
	close_fds_no_stdio(stdio, 2);
	while (cur)
	{
		if (connect_redirect(cur) == -1)
			ft_exit(1);
		cur = cur->next;
	}
	free_redirects(redir);
}
