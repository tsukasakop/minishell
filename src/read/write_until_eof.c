/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_until_eof.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:18:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/23 14:51:33 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  read input and write it on given fd until it is hd_eof or empty line
 *
 * fd: file descriptor to write
 * hd_eof: string represent end
 */
void	write_until_eof(int fd, const char *raw_eof)
{
	const char	*hd_eof;
	char		*line;
	bool		has_quote;
	t_file		*file;

	file = ft_fd2file(fd);
	has_quote = ft_strchr_mul(raw_eof, "\'\"", 2) != NULL;
	hd_eof = ft_g_mmadd(dup_without_quote(raw_eof));
	while (true)
	{
		line = ft_g_mmadd(readline("> "));
		if (line && ft_strcmp(line, hd_eof) == 0)
			break ;
		if (line && !has_quote)
			line = ft_g_mmadd(expand_heredoc_line(line));
		if (line == NULL)
		{
			ft_fprintf(ft_stderr(), ERR_HEREDOC, SHELL_NAME, hd_eof);
			break ;
		}
		ft_fprintf(file, "%s\n", line);
	}
	free(file);
}
