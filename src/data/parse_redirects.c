/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:26 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/22 22:48:55 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:parse_redirects
 * ----------------------------
 * parse the data to be filled in the structure for each redirection symbol.
 * ToDo:ヒアドクがあった場合、ファイルを作成し、add_struct_heredoc関数を処理する機能が必要
 * open関数のために#include <fcntl.h>が必要
 * if (open("/tmp/test", O_WRONLY | O_TRUNC | O_CREAT, 0644) == -1)
 *  perror(NULL);
 * add_struct_heredoc(here, path, "/tmp/test")
 */
void	parse_redirects(t_redirect **reds, t_heredoc **here, \
						char *word, char *path)
{
	size_t	len;

	(void)here;
	len = ft_strlen(word);
	if ((ft_strnstr(word, "<<", len)))
	{
		add_struct_redirect(reds, REDIR_IN, path);
	}
	else if ((ft_strnstr(word, ">>", len)))
		add_struct_redirect(reds, REDIR_APPEND, path);
	else if ((ft_strnstr(word, "<", len)))
		add_struct_redirect(reds, REDIR_IN, path);
	else if ((ft_strnstr(word, ">", len)))
		add_struct_redirect(reds, REDIR_OUT, path);
}
