/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2ecmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:36:46 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/10 16:22:31 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: token2ecmds
 * ----------------------------
 *  expand tokens to ecmds
 */
char	**token2ecmds(t_text_list *tokens)
{
	char		**expanded;

	expanded = expand_all_tokens(tokens);
	if (expanded == NULL)
	{
		expanded = ft_g_mmcalloc(sizeof(char **), 1);
		if (expanded == NULL)
		{
			set_error_type(ERR_SYSCALL);
			print_errmsg_with_str(EM_SYSCALL, NULL);
			return (NULL);
		}
	}
	return (expanded);
}
