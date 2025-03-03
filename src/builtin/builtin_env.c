/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:51:45 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/03 13:16:51 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: builtin_env
 * ----------------------------
 *  show environment variables
 */
int	builtin_env(char **argv)
{
	char	**envp;

	(void)argv;
	envp = ft_getenvp();
	if (envp == NULL)
		return (1);
	while (*envp != NULL)
	{
		ft_printf("%s\n", *envp);
		free(*envp);
		envp++;
	}
	free(envp);
	return (0);
}
