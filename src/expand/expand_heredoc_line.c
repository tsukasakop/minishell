/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:50:41 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/10 16:53:10 by miyuu            ###   ########.fr       */
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
	int		result;

	expanded = ft_g_mmadd(ft_strdup(""));
	if (!expanded)
	{
		set_error_type(ERR_SYSCALL);
		print_errmsg_with_str(EM_SYSCALL, NULL);
		return (NULL);
	}
	while (*raw_line)
	{
		if (*raw_line == '$')
		{
			errno = 0;
			result = expand_and_append_variable((char **)&raw_line, &expanded);
			if (result == -1)
				return (NULL);
			if (result == 1)
				continue ;
		}
		else
			read_bare_string_m((char **)&raw_line, &expanded, "$\0", 2);
	}
	return (expanded);
}
