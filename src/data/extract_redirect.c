/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:42:38 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/25 19:08:27 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: extract_redirect
 * ----------------------------
 *  extract redirect from token_p to redir_p
 *  NOTE: redirect on token_p will be unlinked from list
 */
bool	extract_redirect(t_text_list **token_p, t_redirect **redir_p)
{
	t_redirect	*redir;
	t_text_list	**token_addr;

	*redir_p = NULL;
	token_addr = token_p;
	while (*token_addr)
	{
		if (get_redirect_type((*token_addr)->text) == REDIR_NONE)
			token_addr = &((*token_addr)->next);
		else
		{
			if (!is_valid_redirect_syntax(*token_addr))
			{
				set_error_type(ERR_SYNTAX);
				return (false);
			}
			redir = token2redir((*token_addr)->text, (*token_addr)->next->text);
			if (!redir)
				return (false);
			add_redir_list_last(redir_p, redir);
			*token_addr = (*token_addr)->next->next;
		}
	}
	return (true);
}
