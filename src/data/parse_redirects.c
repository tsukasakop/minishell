/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:26 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/14 01:53:07 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:parse_redirects
 * ----------------------------
 * parse the data to be filled in the structure for each redirection symbol.
 */
void	parse_redirects(t_redirect **redir, t_heredoc **hd_list, \
						char *word, char *path)
{
	t_redirect_type	redir_type;
	int				from_fd;

	redir_type = get_redirect_type(word);
	from_fd = get_redirect_from_fd(word);
	if (redir_type == REDIR_HEREDOC)
		handle_heredoc(redir, hd_list, path, from_fd);
	else
		add_struct_redirect(redir, redir_type, from_fd, path);
}
