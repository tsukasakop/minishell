/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:55:35 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/10 16:28:58 by miyuu            ###   ########.fr       */
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
		print_errmsg_with_str(EM_SYSCALL, NULL);
		ft_exit(1);
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
		ft_exit(1);
	}
	return (success);
}
