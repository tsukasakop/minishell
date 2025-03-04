/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:26 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/04 15:55:10 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:parse_redirects
 * ----------------------------
 * parse the data to be filled in the structure for each redirection symbol.
 */
void	parse_redirects(t_redirect **redir, t_heredoc **hd_list, \
						char *word, char *next_word)
{
	int		from_fd;
	char	*redir_symbol;
	char	*path;

	redir_symbol = has_redirect(word);
	while (redir_symbol)
	{
		from_fd = get_redirect_from_fd(word, redir_symbol - word);
		path = get_redirect_path(redir_symbol, next_word);
		if ((ft_strncmp(redir_symbol, "<<", 2)) == 0)
			handle_heredoc(redir, hd_list, next_word, from_fd);
		else if ((ft_strncmp(redir_symbol, ">>", 2)) == 0)
			add_struct_redirect(redir, REDIR_APPEND, from_fd, path);
		else if ((ft_strncmp(redir_symbol, "<", 1)) == 0)
			add_struct_redirect(redir, REDIR_IN, from_fd, path);
		else if ((ft_strncmp(redir_symbol, ">", 1)) == 0)
			add_struct_redirect(redir, REDIR_OUT, from_fd, path);
		while (*redir_symbol && (*redir_symbol == '>' || *redir_symbol == '<'))
			redir_symbol++;
		redir_symbol = has_redirect(redir_symbol);
	}
}
