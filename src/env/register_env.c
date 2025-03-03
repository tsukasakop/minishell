/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:55:35 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/03 17:55:39 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  manage applying variable assignment statament to env
 */
bool	register_env(char *string)
{
	char	*name;
	char	*value;
	bool	success;

	load_variable_assignment(string, &name, &value);
	if (name == NULL)
	{
		if (errno)
			perror_exit(NULL);
		else
			ft_fprintf(ft_stderr(),
				"bash: export: `%s': not a valid identifier\n", string);
		return (false);
	}
	success = ft_setenv(name, value, true) != -1;
	free(name);
	free(value);
	if (!success)
		perror_exit(NULL);
	return (success);
}
