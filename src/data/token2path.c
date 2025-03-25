/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:14:37 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/25 19:08:27 by mfunakos         ###   ########.fr       */
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
		ft_fprintf(ft_stderr(), "bash: %s: ambiguous redirect\n", token);
		set_error_type(ERR_AMBRDIR);
		return (NULL);
	}
	return (expanded[0]);
}
