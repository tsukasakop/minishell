/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number_redir_token.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:31:14 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/05 02:37:51 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:parse_number_redir_token
 * ----------------------------
 * Returns the length of the token that starts with a digit.
 * If there is a redirection symbol, it will split there.
 */
size_t	parse_number_redir_token(char *scmd_text)
{
	size_t	i;
	int		redir_len;

	i = 0;
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
	return (i);
}
