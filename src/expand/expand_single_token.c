/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_single_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:15:39 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/24 18:37:49 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  expand single token text into string array.
 *  Returns
 *  	NULL:
 *  		failed process (not closed quote, or malloc failed)
 *  	return_value[0] == NULL:
 *  		expanded but no token exits.
 *  		this occurs on expandng empty string without double quotes.
 *  	return_value[1] == NULL:
 *  		general case. expanded to 1 token.
 *  	return_value[>=2] == NULL:
 *  		expanded to more than 1 token, by expanding variable without quotes.
 */
char	**expand_single_token(char *orig)
{
	char	*buffer;
	char	**fixed;
	char	*cur;

	buffer = NULL;
	fixed = ft_g_mmcalloc(sizeof(char *), 1);
	if (!fixed)
	{
		//TODO:SET errno
		return (perror_return_null(NULL));
	}
	cur = orig;
	while (*cur)
	{
		//TODO:expand_bare_variable関数以外は、返り値や引数の値でエラーチェックできない。
		//なので。errnoでmalloc失敗を確認する→expand_bare_variable関数もerrnoチェックでいいのでは？
		// errno = 0;
		if (*cur == '\'')
			expand_single_quote(&cur, &buffer);
		else if (*cur == '\"')
			expand_double_quote(&cur, &buffer);
		else if (*cur == '$')
		{
			expand_bare_variable(&cur, &buffer, &fixed);
			if (!fixed)
				return (NULL);
		}
		else
			expand_bare_string(&cur, &buffer);
		// if (errno == ENOMEM)
			// return (NULL);
	}
	if (buffer != NULL)
	{
		append_str(&fixed, buffer);
		if (!fixed)
			return (NULL);
	}
	return (fixed);
}
