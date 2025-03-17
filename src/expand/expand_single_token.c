/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_single_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:15:39 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/15 12:50:07 by tkondo           ###   ########.fr       */
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
	fixed = ft_calloc(sizeof(char *), 1);
	cur = orig;
	while (*cur)
	{
		if (*cur == '\'')
			expand_single_quote(&cur, &buffer);
		else if (*cur == '\"')
			expand_double_quote(&cur, &buffer);
		else if (*cur == '$')
			expand_bare_variable(&cur, &buffer, &fixed);
		else
			expand_bare_string(&cur, &buffer);
	}
	if (buffer != NULL)
		append_str(&fixed, buffer);
	return (fixed);
}
