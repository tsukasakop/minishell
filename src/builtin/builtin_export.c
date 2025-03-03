/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:07:28 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/03 18:09:49 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: builtin_export
 * ----------------------------
 *
 */
int	builtin_export(char **argv)
{
	size_t	i;
	bool	success;

	i = 0;
	// TODO: export用の表示に変更する
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
