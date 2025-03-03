/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:55:32 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/03 19:55:51 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:get_redir_length
 * ----------------------------
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
