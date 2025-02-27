/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_until_eof.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:18:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/27 13:33:17 by tkondo           ###   ########.fr       */
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
void	write_until_eof(int fd, const char *hd_eof)
{
	char	*line;
	t_file	*file;

	file = ft_fd2file(fd);
	while (true)
	{
		line = readline("> ");
		if (line == NULL)
		{
			ft_fprintf(ft_stderr(), ERR_HEREDOC, SHELL_NAME, hd_eof);
			break ;
		}
		if (ft_strcmp(line, hd_eof) == 0)
			break ;
		ft_fprintf(file, "%s\n", line);
		free(line);
	}
	free(line);
	free(file);
}
