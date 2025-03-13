/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_env_connect_redirects.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:48:50 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/13 19:32:32 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:cur_env_connect_redirects
 * ----------------------------
 * In the parent process, Parse redirect type and perform redirection processing.
 * TODO: merge connect_redirects
 */
int	cur_env_connect_redirects(t_redirect *redir)
{
	if (redir->type == REDIR_IN)
		return (cur_env_redirects_stdin(redir));
	else if (redir->type == REDIR_OUT || \
			redir->type == REDIR_APPEND)
		return (cur_env_redirects_stdout(redir));
	return (-1);
}
