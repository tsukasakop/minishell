/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline2_scmd_texts.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:10:52 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 04:01:16 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:cmdline2_scmd_texts
 * ----------------------------
 * Returns a pipeline that separates cmd_line with pipes.
 */
char	**cmdline2_scmd_texts(const char *cmd_line)
{
	char	**scmd_texts;
	char	*error_msg;

	error_msg = validate_cmd_line_syntax(cmd_line);
	if (error_msg)
	{
		set_error_type(ERR_SYNTAX);
		print_errmsg_with_str(EM_SYNTAX, error_msg);
		return (NULL);
	}
	scmd_texts = fill_scmd_texts(cmd_line);
	return (scmd_texts);
}
