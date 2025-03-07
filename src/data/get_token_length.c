/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:38:24 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/05 02:31:41 by miyuu            ###   ########.fr       */
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
	if (scmd_text[0] == '>' || scmd_text[0] == '<')
		return (get_redir_length(scmd_text));
	if (ft_isdigit(scmd_text[0]))
		return (parse_number_redir_token(scmd_text));
	return (parse_general_token(scmd_text));
}
