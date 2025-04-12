/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:54:36 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/12 20:39:53 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:create_heredoc_file
 * ----------------------------
 * Creates a unique /tmp/heredoc_* file and returns its path.
 */
char	*create_heredoc_file(void)
{
	int				fd_random;
	char			*filename;

	fd_random = open("/dev/urandom", O_RDONLY);
	if (fd_random > 0)
	{
		filename = create_heredoc_randfile(fd_random);
		close(fd_random);
	}
	else
		filename = create_heredoc_seqfile();
	return (filename);
}
