/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_until_eof.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:18:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/10 16:58:14 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  Expand raw_eof and writes input to the specified fd file.
 *
 * fd: file descriptor to write
 * hd_eof: string represent end
 */
void	write_until_eof(int fd, const char *raw_eof)
{
	const char	*hd_eof;
	bool		has_quote;

	has_quote = ft_strchr_mul(raw_eof, "\'\"", 2) != NULL;
	hd_eof = dup_without_quote(raw_eof);
	if (hd_eof == NULL)
		return ;
	read_and_write_heredoc_lines(fd, hd_eof, has_quote);
}
