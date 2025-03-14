/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:26 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/15 01:55:41 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:token2redir
 * ----------------------------
 * parse the data to be filled in the structure for each redirection symbol.
 */
t_redirect	*token2redir(char *word, char *path)
{
	t_redirect_type	redir_type;
	int				from_fd;
	t_redirect		*redir;

	redir_type = get_redirect_type(word);
	from_fd = get_redirect_from_fd(word);
	if (redir_type == REDIR_HEREDOC)
		redir = handle_heredoc(path, from_fd);
	else
		redir = add_struct_redirect(redir_type, from_fd, path);
	return (redir);
}
