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
		if (cur->next == NULL)
			syntax_error_handle("newline");
		else
			syntax_error_handle(cur->next->text);
		//ToDO；終了ステータスどうする？exitできないから設定できない。
		//いっそ子プロセスまで実行させて、pathがNULLだったらシンタックスにする？
		//でも`ls -l > out>`みたいに、シンタックスエラーになるとき、outは作られないから子プロセス生成前にやるのか
		return (false);
	}
	return (true);
}
