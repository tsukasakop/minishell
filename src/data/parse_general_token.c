/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:31:34 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/05 02:36:08 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:parse_general_token
 * ----------------------------
 * Returns the length of a general token, handling quotes properly.
 */
size_t	parse_general_token(char *scmd_text)
{
	size_t	i;

	i = 0;
	while (scmd_text[i] && !ft_isifs(scmd_text[i]) && \
	scmd_text[i] != '>' && scmd_text[i] != '<')
	{
		if (scmd_text[i] == '"' || scmd_text[i] == '\'')
			i += skip_quote_text(&scmd_text[i], scmd_text[i]);
		else
			i++;
	}
	return (i);
}
