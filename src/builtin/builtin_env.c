/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:51:45 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/21 17:13:15 by tkondo           ###   ########.fr       */
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
		ft_printf("%s\n", envp[i]);
		i++;
	}
	free_null_terminated_array((void **)envp);
	return (0);
}
