/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:38:24 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/05 00:43:29 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Returns the length of a token,
 * considering redirections and IFS(' ', '\t', '\n').
 */
size_t	get_token_length(char *scmd_text)
{
	size_t	i;
	int		redir_len;

	i = 0;
	redir_len = 0;
	if (scmd_text[i] == '>' || scmd_text[i] == '<')
		i = get_redir_length(&scmd_text[i]);
	else
	{
		while (ft_isdigit(scmd_text[i]))
			i++;
		redir_len = get_redir_length(&scmd_text[i]);
		if (redir_len != 0)
			i += redir_len;
		else
		{
			while (scmd_text[i] && !ft_isifs(scmd_text[i]) && \
					scmd_text[i] != '>' && scmd_text[i] != '<')
				i++;
		}
	}
	return (i);
}
