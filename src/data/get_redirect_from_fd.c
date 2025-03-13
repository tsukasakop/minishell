/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_from_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:51:13 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/14 01:13:14 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:get_redirect_from_fd
 * ----------------------------
 * Finds the number to the left of the redirect and returns it as an int.
 * If there is no number, returns 0 if the redirect is `<`,
 * or 1 if the redirect is `>`.
 */
int	get_redirect_from_fd(char *cmds_text)
{
	int	digit;
	int	len;

	digit = ft_atoi(cmds_text);
	if (digit != 0)
		return (digit);
	else
	{
		len = ft_strlen(cmds_text);
		if (cmds_text[len -1] == '<')
			return (0);
		else if (cmds_text[len -1] == '>')
			return (1);
	}
	return (-1);
}
