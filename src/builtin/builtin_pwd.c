/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:22:54 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/06 18:46:24 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: builtin_pwd
 * ----------------------------
 *  print current working directory
 *  TODO: use env $PWD
 */
int	builtin_pwd(char **argv)
{
	char	*cwd;
	int		ret;

	(void)argv;
	cwd = getcwd(NULL, 0);
	if (cwd)
		ft_putendl_fd(cwd, STDOUT_FILENO);
	ret = cwd == NULL;
	free(cwd);
	return (ret);
}
