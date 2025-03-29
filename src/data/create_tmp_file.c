/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tmp_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:43:09 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/29 20:25:54 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:create_tmp_file
 * ----------------------------
 * Creates a unique /tmp/heredoc_* file and returns its path.
 */
char	*create_tmp_file(void)
{
	int		count;
	char	*filename;
	char	*num;
	int		fd;

	count = 0;
	filename = NULL;
	num = NULL;
	fd = -1;
	while (fd == -1)
	{
		num = ft_g_mmadd(ft_itoa(count++));
		if (!num)
		{
			set_error_type(ERR_SYSCALL);
			perror_with_shellname(NULL);
			return (NULL);
		}
		filename = ft_g_mmadd(ft_strjoin("/tmp/heredoc_", num));
		if (!filename)
		{
			set_error_type(ERR_SYSCALL);
			perror_with_shellname(NULL);
			return (NULL);
		}
		fd = open(filename, O_CREAT | O_EXCL, 0600);
	}
	close(fd);
	return (filename);
}
