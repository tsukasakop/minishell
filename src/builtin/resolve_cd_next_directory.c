/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_cd_next_directory.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:43:48 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/09 00:47:58 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: resolve_cd_next_directory
 * ----------------------------
 * Resolves the destination directory from the argv.
 */
char	*resolve_cd_next_directory(char **argv, char *old_dir)
{
	if (argv[0] && argv[1])
	{
		ft_fprintf(ft_stderr(), "bash: cd: too many arguments\n");
		return (NULL);
	}
	if (argv[0] && ft_strcmp(argv[0], "-") == 0 && old_dir == NULL)
	{
		ft_fprintf(ft_stderr(), "bash: cd: OLDPWD not set\n");
		return (NULL);
	}
	if (argv[0] == NULL || ft_strcmp(argv[0], "~") == 0)
		return (ft_getenv("HOME"));
	else if (ft_strcmp(argv[0], "-") == 0)
		return (old_dir);
	else
		return (argv[0]);
}
