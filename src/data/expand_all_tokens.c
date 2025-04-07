/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_all_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 00:56:14 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/08 00:56:20 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: expand_all_tokens
 * ----------------------------
 * Expands all text in the t_text_list *token.
 */
char	**expand_all_tokens(t_text_list *tokens)
{
	char		**expanded;
	char		**tmp;
	t_text_list	*cur_token;

	expanded = NULL;
	cur_token = tokens;
	while (cur_token)
	{
		tmp = expand_single_token(cur_token->text);
		if (tmp == NULL)
			return (NULL);
		if (expanded == NULL)
			expanded = tmp;
		else
			expanded = (char **)null_terminated_array_join(\
										(void **)expanded, \
										(void **)tmp);
		cur_token = cur_token->next;
	}
	return (expanded);
}
