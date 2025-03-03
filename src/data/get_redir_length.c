/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:55:32 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/03 20:25:23 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:get_redir_length
 * ----------------------------
 *  Returns the length of a redirection operator. (>, >>, <, <<).
 * Even if there are three or more redirection symbols,
 * they only count up to two.
 */
int	get_redir_length(char *scmd_text)
{
	int	con;

	con = 0;
	if (*scmd_text == '>' || *scmd_text == '<')
	{
		con++;
		if (*(scmd_text + 1) && *scmd_text == *(scmd_text + 1))
			con++;
	}
	return (con);
}
