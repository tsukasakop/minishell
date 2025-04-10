/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:50:15 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/10 17:01:22 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: builtin_cd
 * ----------------------------
 *  change direcry
 *  TODO:
 *   - use env $OLDPWD, $PWD
 *   - refactor error messaged
 */
int	builtin_cd(char **argv)
{
	static char	*old_dir;
	char		*cur_dir;
	char		*next_dir;

	next_dir = resolve_cd_next_directory(argv, old_dir);
	if (next_dir == NULL)
		return (1);
	cur_dir = getcwd(NULL, 0);
	if (chdir(next_dir) == -1)
	{
		print_errmsg_with_str(EM_CD_SYSCALL, next_dir);
		free(cur_dir);
		return (1);
	}
	if (argv[0] && ft_strcmp(argv[0], "-") == 0)
		ft_putendl_fd(next_dir, STDOUT_FILENO);
	free(old_dir);
	old_dir = cur_dir;
	return (0);
}
