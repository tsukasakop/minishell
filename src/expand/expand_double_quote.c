/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_double_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:49:04 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/15 12:49:35 by tkondo           ###   ########.fr       */
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
	char	*var;
	char	*tmp;

	(*cur_p)++;
	while (**cur_p != '\"')
	{
		if (**cur_p == '$')
		{
			var = read_variable_m(cur_p, buf_p);
			if (!var)
				continue ;
			tmp = ft_strnjoin(*buf_p, var, ft_strlen(var));
			*buf_p = tmp;
		}
		else
			read_bare_string_m(cur_p, &*buf_p, "\"$", 2);
	}
	tmp = ft_strnjoin(*buf_p, "", 0);
	*buf_p = tmp;
	(*cur_p)++;
}
