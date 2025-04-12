/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:55:35 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/12 22:26:03 by miyuu            ###   ########.fr       */
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

	errno = 0;
	load_variable_assignment(string, &name, &value);
	if (errno)
	{
		print_errmsg_with_str(EM_SYSCALL, NULL);
		return (false);
	}
	if (!is_valid_identifier(name))
	{
		print_errmsg_with_str(EM_EXPO_BADID, string);
		return (false);
	}
	success = ft_setenv(name, value, true) != -1;
	if (!success)
	{
		print_errmsg_with_str(EM_SYSCALL, NULL);
		return (false);
	}
	return (success);
}
