/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:51:33 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/28 22:58:24 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:get_redirect_path
 * ----------------------------
 * Finds and returns the redirect path.
 */
char	*get_redirect_path(char *redir_symbol, char *next_word)
{
	char	*next;
	size_t	len;
	char	*path;

	while (*redir_symbol && (*redir_symbol == '>' || *redir_symbol == '<'))
		redir_symbol++;
	if (!*redir_symbol)
		return (next_word);
	next = has_redirect(redir_symbol);
	if (!next)
		return (redir_symbol);
	len = next - redir_symbol;
	path = ft_strndup(redir_symbol, len);
	return (path);
}
