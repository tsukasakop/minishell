/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_redirect.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:48:50 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/14 03:16:59 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:connect_redirect
 * ----------------------------
 * In the parent process, Parse redirect type and perform redirection processing.
 * TODO: merge connect_redirect
 */
int	connect_redirect(t_redirect *redir)
{
	int		o_flags;

	if (redir->type == REDIR_IN || redir->type == REDIR_HEREDOC)
		o_flags = O_RDONLY;
	else if (redir->type == REDIR_OUT)
		o_flags = O_WRONLY | O_TRUNC | O_CREAT;
	else if (redir->type == REDIR_APPEND)
		o_flags = O_WRONLY | O_APPEND | O_CREAT;
	else
		return (-1);
	return (redirect_with_oflags(redir, o_flags));
}
