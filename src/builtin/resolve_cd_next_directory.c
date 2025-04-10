/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_cd_next_directory.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:43:48 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/10 17:00:51 by miyuu            ###   ########.fr       */
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
		print_errmsg_with_str(EM_MANYARG, "cd");
		return (NULL);
	}
	if (argv[0] && ft_strcmp(argv[0], "-") == 0 && old_dir == NULL)
	{
		print_errmsg_with_str(EM_CD_OPWDNSET, NULL);
		return (NULL);
	}
	if (argv[0] == NULL || ft_strcmp(argv[0], "~") == 0)
		return (ft_getenv("HOME"));
	else if (ft_strcmp(argv[0], "-") == 0)
		return (old_dir);
	else
		return (argv[0]);
}
