/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc_seqfile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:34:05 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/12 20:39:14 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:create_heredoc_seqfile
 * ----------------------------
 * Creates a unique /tmp/heredoc_<number> filename
 * by incrementing a counter until a non-existing filename is found.
 */
char	*create_heredoc_seqfile(void)
{
	int		count;
	char	*filename;
	int		fd;

	count = 0;
	filename = NULL;
	fd = -1;
	while (fd == -1)
	{
		filename = ft_g_mmadd(ft_strjoin(HEREDOC_TMP_PREFIX,
					ft_g_mmadd(ft_itoa(count++))));
		if (!filename)
		{
			set_error_type(ERR_SYSCALL);
			print_errmsg_with_str(EM_SYSCALL, NULL);
			return (NULL);
		}
		fd = open(filename, O_CREAT | O_EXCL, 0600);
	}
	close(fd);
	return (filename);
}
