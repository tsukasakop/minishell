/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:46:43 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/10 18:47:07 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:handle_redirects
 * ----------------------------
 * Set fd for redirection.
 */
int	*handle_redirects(t_redirect *redir, int fd_count)
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
		if (apply_redirects(cur, keep_fds, i) == -1)
		{
			restore_from_fds(keep_fds, i);
			return (NULL);
		}
		cur = cur->next;
		i++;
	}
	return (keep_fds);
}
