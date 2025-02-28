/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_heredocs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:18:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/27 14:39:48 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  write heredocs by using hd_list info
 *
 * Returns false if falure on write heredocs, otherwise true
 * TODO: エラー出力
 */
bool	write_heredocs(t_heredoc *hd_list)
{
	int	fd;

	if (hd_list == NULL)
		return (true);
	while (hd_list != NULL)
	{
		fd = open(hd_list->path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd == -1)
			return (false);
		if (!write_until_eof_on_chproc(fd, hd_list->eof))
		{
			close(fd);
			return (false);
		}
		if (close(fd) == -1)
			return (false);
		hd_list = hd_list->next;
	}
	return (true);
}
