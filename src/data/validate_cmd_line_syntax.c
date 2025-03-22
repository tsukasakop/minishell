/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cmd_line_syntax.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:21:12 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/22 14:40:45 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:validate_cmd_line_syntax
 * ----------------------------
 * Validates cmd_line for syntax errors.
 * If there is an error, the target string is returned.
 * if there is no error, NULL is returned.
 */
char	*validate_cmd_line_syntax(const char *cmd_line)
{
	if (!is_valid_pipe_syntax(cmd_line))
		return ("|");
	if (!is_valid_quote_syntax(cmd_line, '"'))
		return ("\"");
	if (!is_valid_quote_syntax(cmd_line, '\''))
		return ("'");
	return (NULL);
}
