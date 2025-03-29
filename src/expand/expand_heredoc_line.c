/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:50:41 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/29 20:25:54 by miyuu            ###   ########.fr       */
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
		set_error_type(ERR_SYSCALL);
		perror_with_shellname(NULL);
		return (NULL);
	}
	while (*raw_line)
	{
		if (*raw_line == '$')
		{
			errno = 0;
			var = read_variable_m((char **)&raw_line, &expanded);
			if (var == NULL && errno == ENOMEM)
				return (NULL);
			if (!var)
				continue ;
			expanded = ft_strnjoin(expanded, var, ft_strlen(var));
			if (!expanded)
			{
				set_error_type(ERR_SYSCALL);
				perror_with_shellname(NULL);
				return (NULL);
			}
		}
		else
			read_bare_string_m((char **)&raw_line, &expanded, "$\0", 2);
	}
	return (expanded);
}
