/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:27:06 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/22 02:21:18 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * free memory of redirects
 */
void	free_redirects(t_redirect *reds)
{
	t_redirect	*tmp;

	while (reds != NULL)
	{
		free((char *)reds->path);
		tmp = reds;
		reds = reds->next;
		free(tmp);
	}
}

