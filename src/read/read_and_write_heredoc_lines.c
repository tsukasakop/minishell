/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_write_heredoc_lines.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:40:59 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/10 16:57:37 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:read_and_write_heredoc_lines
 * ----------------------------
 * read input and write it on given fd until it is hd_eof or empty line
 */
void	read_and_write_heredoc_lines(int fd, \
					const char *hd_eof, bool has_quote)
{
	char	*line;

	while (true)
	{
		line = get_readline_safely("> ");
		if (line == NULL && errno == ENOMEM)
			return ;
		if (line && ft_strcmp(line, hd_eof) == 0)
			break ;
		if (line && !has_quote)
		{
			line = expand_heredoc_line(line);
			if (line == NULL && errno == ENOMEM)
				return ;
		}
		if (line == NULL)
		{
			print_errmsg_with_str(EM_HEREDOC, (char *)hd_eof);
			break ;
		}
		ft_putendl_fd(line, fd);
	}
}
