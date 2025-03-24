/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:50:41 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/24 18:23:36 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: expand_heredoc_line
 * ----------------------------
 *  expand string for heredoc line
 */
char	*expand_heredoc_line(const char *raw_line)
{
	char	*expanded;
	char	*var;

	expanded = ft_g_mmadd(ft_strdup(""));
	if (!expanded)
	{
		//TODO:SET errno
		return (perror_return_null(NULL));
	}
	while (*raw_line)
	{
		if (*raw_line == '$')
		{
			var = read_variable_m((char **)&raw_line, &expanded);
			// TODO:read_variable_m関数内のmalloc失敗時の処理を考える
			//NULLに意味を持ってる場合、errnoでエラー判定する
			// if (var == NULL && errno == ENOMEM)
				// return (NULL);
			if (!var)
				continue ;
			expanded = ft_strnjoin(expanded, var, ft_strlen(var));
			if (!expanded)
			{
				// TODO:SET errno
				return (perror_return_null(NULL));
			}
		}
		else
			read_bare_string_m((char **)&raw_line, &expanded, "$\0", 2);
	}
	return (expanded);
}
