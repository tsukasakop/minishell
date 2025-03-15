/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_heredocs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:18:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/15 18:27:01 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  write heredoc by using hd_list info
 *
 * Returns false if falure on write heredoc, otherwise true
 * TODO: エラー出力
 * TODO: 単体で処理する
 */
bool	write_heredoc(char *eof, char *path)
{
	int	fd;

	if (path == NULL)
		return (true);
	fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		return (false);
	if (!write_until_eof_on_chproc(fd, eof))
	{
		close(fd);
		return (false);
	}
	if (close(fd) == -1)
		return (false);
	return (true);
}
