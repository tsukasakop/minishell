/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:07:28 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/07 22:44:56 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: builtin_export
 * ----------------------------
 * TODO: export用の表示に変更する
 */
int	builtin_export(char **argv)
{
	size_t	i;
	bool	success;

	i = 0;
	if (argv[i] == NULL)
		return (builtin_env(NULL));
	success = true;
	while (argv[i] != NULL)
	{
		success = (register_env(argv[i]) && success);
		i++;
	}
	return (!success);
}
