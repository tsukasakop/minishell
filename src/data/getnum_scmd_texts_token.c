/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnum_scmd_texts_token.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:23:20 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/20 17:24:37 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:getnum_scmd_texts_token
 * ----------------------------
 * Returns the number of scmd_texts tokens in cmd_line.
 */
size_t	getnum_scmd_texts_token(const char *cmd_line)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (cmd_line[i])
	{
		i += get_tokenize_pipe_length(&cmd_line[i]);
		if (cmd_line[i] == '|')
		{
			num++;
			i++;
		}
	}
	return (num + 1);
}
