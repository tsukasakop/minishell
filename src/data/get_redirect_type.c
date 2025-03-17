/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:46 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/17 13:32:20 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:get_redirect_type
 * ----------------------------
 * Returns the type of the redirection symbol.
 */
t_redirect_type	get_redirect_type(char *word)
{
	size_t	len;

	if (!word)
		return (REDIR_NONE);
	len = ft_strlen(word);
	if (len >= 2 && ft_strncmp(word + len - 2, "<<", 2) == 0)
		return (REDIR_HEREDOC);
	else if (len >= 2 && ft_strncmp(word + len - 2, ">>", 2) == 0)
		return (REDIR_APPEND);
	else if (word[len - 1] == '<')
		return (REDIR_IN);
	else if (word[len - 1] == '>')
		return (REDIR_OUT);
	return (REDIR_NONE);
}
