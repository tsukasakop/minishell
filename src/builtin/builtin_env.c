/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:51:45 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/06 18:46:32 by miyuu            ###   ########.fr       */
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
	size_t	i;

	(void)argv;
	envp = ft_getenvp();
	if (envp == NULL)
		return (1);
	i = 0;
	while (envp[i] != NULL)
	{
		ft_putendl_fd(envp[i], STDOUT_FILENO);
		i++;
	}
	free_null_terminated_array((void **)envp);
	return (0);
}
