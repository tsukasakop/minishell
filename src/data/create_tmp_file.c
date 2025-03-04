/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tmp_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:43:09 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/04 14:45:28 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 */
char	*create_tmp_file(void)
{
	int		count;
	char	*filename;
	char	*num;
	int		fd;

	count = 0;
	while (1)
	{
		num = ft_itoa(count++);
		filename = ft_strjoin("/tmp/heredoc_", num);
		free(num);
		if (access(filename, F_OK) != 0)
		{
			fd = open(filename, O_CREAT | O_EXCL, 0600);
			if (fd != -1)
			{
				close(fd);
				return (filename);
			}
		}
		free(filename);
	}
}
