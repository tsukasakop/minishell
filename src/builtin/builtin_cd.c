/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:47:30 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/01 16:50:15 by tkondo           ###   ########.fr       */
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

	if (argv[0] && argv[1])
	{
		print_errmsg_with_str(EM_MANYARG, "cd");
		return (1);
	}
	if (argv[0] && ft_strcmp(argv[0], "-") == 0 && old_dir == NULL)
	{
		print_errmsg_with_str(EM_CD_OPWDNSET, NULL);
		return (1);
	}
	if (argv[0] == NULL || ft_strcmp(argv[0], "~") == 0)
		next_dir = ft_getenv("HOME");
	else if (ft_strcmp(argv[0], "-") == 0)
		next_dir = old_dir;
	else
		next_dir = argv[0];
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
