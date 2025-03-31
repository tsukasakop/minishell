/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:14:37 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/27 20:09:53 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: token2path
 * ----------------------------
 * expand token to file path
 */
char	*token2path(char *token)
{
	char	**expanded;

	expanded = expand_single_token(token);
	if (expanded == NULL)
		perror_exit(NULL);
	if (null_terminated_array_len((void **)expanded) != 1)
	{
		set_error_type(ERR_AMBRDIR);
		ft_fprintf(ft_stderr(), "bash: %s: ambiguous redirect\n", token);
		return (NULL);
	}
	return (expanded[0]);
}
