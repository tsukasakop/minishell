/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:14:37 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/20 09:00:47 by tkondo           ###   ########.fr       */
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
		return (NULL);
	}
	return (expanded[0]);
}
