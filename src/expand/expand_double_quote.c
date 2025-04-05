/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_double_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:49:04 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/06 04:01:16 by miyuu            ###   ########.fr       */
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
		errno = 0;
		if (**cur_p == '$')
		{
			var = read_variable_m(cur_p, buf_p);
			if (var == NULL && errno == ENOMEM)
				return ;
			if (!var)
				continue ;
			tmp = ft_strnjoin(*buf_p, var, ft_strlen(var));
			if (var == NULL)
			{
				set_error_type(ERR_SYSCALL);
				print_errmsg_with_str(EM_SYSCALL, NULL);
				return ;
			}
			*buf_p = tmp;
		}
		else
			read_bare_string_m(cur_p, &*buf_p, "\"$", 2);
		if (errno == ENOMEM)
			return ;
	}
	tmp = ft_strnjoin(*buf_p, "", 0);
	*buf_p = tmp;
	(*cur_p)++;
}
