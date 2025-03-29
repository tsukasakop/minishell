/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_until_eof.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:18:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/29 20:25:54 by miyuu            ###   ########.fr       */
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
	hd_eof = dup_without_quote(raw_eof);
	if (hd_eof == NULL)
		return ;
	while (true)
	{
		line = ft_g_mmadd(readline("> "));
		if (line == NULL && errno == ENOMEM)
		{
			set_error_type(ERR_SYSCALL);
			perror_with_shellname(NULL);
			return ;
		}
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
			ft_fprintf(ft_stderr(), ERR_HEREDOC, SHELL_NAME, hd_eof);
			break ;
		}
		ft_fprintf(file, "%s\n", line);
	}
	free(file);
}
