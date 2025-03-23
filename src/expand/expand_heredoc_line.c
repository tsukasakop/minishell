/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:50:41 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/23 14:51:14 by tkondo           ###   ########.fr       */
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
		return (NULL);
	while (*raw_line)
	{
		if (*raw_line == '$')
		{
			var = read_variable_m((char **)&raw_line, &expanded);
			if (!var)
				continue ;
			expanded = ft_strnjoin(expanded, var, ft_strlen(var));
			if (!expanded)
				break ;
		}
		else
			read_bare_string_m((char **)&raw_line, &expanded, "$\0", 2);
	}
	return (expanded);
}
