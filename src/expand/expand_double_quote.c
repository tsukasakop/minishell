/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_double_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:49:04 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/10 16:33:47 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: expand_double_quote
 * ----------------------------
 *  read string and vaiable on double quote and store it on buf_p
 */
void	expand_double_quote(char **cur_p, char **buf_p)
{
	char	*tmp;
	int		result;

	(*cur_p)++;
	while (**cur_p != '\"')
	{
		errno = 0;
		if (**cur_p == '$')
		{
			result = expand_and_append_variable(cur_p, buf_p);
			if (result == -1)
				return ;
			if (result == 1)
				continue ;
		}
		else
		{
			read_bare_string_m(cur_p, buf_p, "\"$", 2);
			if (errno == ENOMEM)
				return ;
		}
	}
	tmp = ft_strnjoin(*buf_p, "", 0);
	*buf_p = tmp;
	(*cur_p)++;
}
