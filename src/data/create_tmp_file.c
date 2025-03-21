/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tmp_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:43:09 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/05 17:43:40 by tkondo           ###   ########.fr       */
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
		filename = ft_g_mmadd(ft_strjoin("/tmp/heredoc_", num));
		fd = open(filename, O_CREAT | O_EXCL, 0600);
	}
	close(fd);
	return (filename);
}
