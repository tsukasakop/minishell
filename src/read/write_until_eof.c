/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_until_eof.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:18:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/25 22:28:42 by miyuu            ###   ########.fr       */
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
	//TODO: malloc失敗時の処理考える。return (false);にする？
	if (hd_eof == NULL)
	{
		// TODO:SET errno
		perror_with_shellname(NULL);
		// return (false);
	}
	while (true)
	{
		errno = 0;
		line = ft_g_mmadd(readline("> "));
		//TODO: malloc失敗時の処理考える。return (false);にする？
		if (line == NULL && errno == ENOMEM)
		{
			// TODO:SET errno
			perror_with_shellname(NULL);
			// return (false);
		}
		if (line && ft_strcmp(line, hd_eof) == 0)
			break ;
		if (line && !has_quote)
		{
			line = expand_heredoc_line(line);
			//TODO: malloc失敗時の処理考える。return (false);にする？
			if (line == NULL && errno == ENOMEM)
			{
				// return (false);
				break ;
			}
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
