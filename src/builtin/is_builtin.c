/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:11:20 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/28 16:31:15 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  return true if arg text is builtin
 */
bool	is_builtin(char *ecmd)
{
	if (ecmd == NULL)
		return (false);
	if (ft_strcmp(ecmd, "cd") == 0)
		return (true);
	if (ft_strcmp(ecmd, "echo") == 0)
		return (true);
	if (ft_strcmp(ecmd, "env") == 0)
		return (true);
	if (ft_strcmp(ecmd, "exit") == 0)
		return (true);
	if (ft_strcmp(ecmd, "export") == 0)
		return (true);
	if (ft_strcmp(ecmd, "pwd") == 0)
		return (true);
	if (ft_strcmp(ecmd, "unset") == 0)
		return (true);
	return (false);
}
