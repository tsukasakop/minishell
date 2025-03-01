/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:22:54 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/01 15:50:11 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: builtin_pwd
 * ----------------------------
 *  print current working directory
 */
int	builtin_pwd(char **argv)
{
	char	*cwd;

	(void)argv;
	cwd = getcwd(NULL, 0);
	if (cwd)
		ft_printf("%s\n", cwd);
	free(cwd);
	return (cwd == NULL);
}
