/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:55:35 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/08 01:36:21 by miyuu            ###   ########.fr       */
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
		perror_exit(NULL);
	if (!is_valid_identifier(name))
	{
		ft_fprintf(ft_stderr(),
			"bash: export: `%s': not a valid identifier\n", string);
		return (false);
	}
	success = ft_setenv(name, value, true) != -1;
	if (!success)
		perror_exit(NULL);
	return (success);
}
