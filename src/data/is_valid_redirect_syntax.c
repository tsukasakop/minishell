/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_redirect_syntax.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:42:47 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/17 13:32:20 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:is_valid_redirect_syntax
 * ----------------------------
 * Checks if a redirection token has a valid next token.
 * If it doesn't, prints an error.
 */
bool	is_valid_redirect_syntax(t_text_list *cur)
{
	if (cur->next == NULL || get_redirect_type(cur->next->text) != REDIR_NONE)
	{
		set_error_type(ERR_SYNTAX);
		if (cur->next == NULL)
			print_errmsg_with_str(EM_SYNTAX, "newline");
		else
			print_errmsg_with_str(EM_SYNTAX, cur->next->text);
		return (false);
	}
	return (true);
}
