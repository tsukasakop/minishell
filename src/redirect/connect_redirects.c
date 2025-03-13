/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:13:07 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/13 19:41:58 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:connect_redirects
 * ----------------------------
 * Parse redirect type and perform redirection processing.
 * TODO: merge cur_env_connect_redirects
 * TODO: 名前を単数系にする
 */
void	connect_redirects(t_redirect *redir)
{
	if (redir->type == REDIR_IN)
		redirects_stdin(redir);
	else if (redir->type == REDIR_OUT || \
			redir->type == REDIR_APPEND)
		redirects_stdout(redir);
}
