/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_from_fds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:46:43 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/08 04:05:51 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:backup_from_fds
 * ----------------------------
 * Saves from_fd and their duplicates into an array.
 */
int	*backup_from_fds(t_redirect *redir, int fd_count)
{
	t_redirect	*cur;
	int			i;
	int			*keep_fds;

	cur = redir;
	keep_fds = malloc(sizeof(int) * fd_count * 2);
	if (!keep_fds)
	{
		perror_return(NULL, -1);
		return (NULL);
	}
	i = 0;
	while (cur)
	{
		keep_fds[i * 2] = cur->from_fd;
		keep_fds[i * 2 + 1] = dup(cur->from_fd);
		if (keep_fds[i * 2 + 1] == -1)
		{
			if (errno == EBADF)
				keep_fds[i * 2 + 1] = cur->from_fd;
			else
			{
				perror(ft_itoa(cur->from_fd));
				return (NULL);
			}
		}
		cur = cur->next;
		i++;
	}
	return (keep_fds);
}
