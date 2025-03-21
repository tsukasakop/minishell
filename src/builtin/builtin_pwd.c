/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:22:54 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/21 17:51:25 by tkondo           ###   ########.fr       */
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
		ft_printf("%s\n", cwd);
	ret = cwd == NULL;
	free(cwd);
	return (ret);
}
