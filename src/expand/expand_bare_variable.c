/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bare_variable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:48:13 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/25 22:50:52 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: expand_bare_variable
 * ----------------------------
 *  read variable on cur_p, and store it on buf_p and fixed_p
 */
void	expand_bare_variable(char **cur_p, char **buf_p, char ***fixed_p)
{
	char	*var;

	var = read_variable_m(cur_p, buf_p);
	if (var == NULL && errno == ENOMEM)
	{
		*fixed_p = NULL;
		return ;
	}
	while (var && *var)
	{
		if (ft_isifs(*var))
		{
			if (*buf_p != NULL)
			{
				append_str(fixed_p, *buf_p);
				if (fixed_p == NULL)
					return ;
			}
			*buf_p = NULL;
			var++;
		}
		else
			read_bare_string_m(&var, buf_p, (char [4]){' ', '\t', '\n', '\0'},
				4);
	}
}
