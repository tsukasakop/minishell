/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_from_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:51:13 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/28 22:57:10 by miyuu            ###   ########.fr       */
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
int	get_redirect_from_fd(char *cmds_text, int i)
{
	int	m;

	m = i;
	while (i > 0 && ft_isdigit(cmds_text[i - 1]))
		i--;
	if (i < m)
		return (ft_atoi(&cmds_text[i]));
	if (cmds_text[m] == '<')
		return (0);
	else if (cmds_text[m] == '>')
		return (1);
	return (-1);
}
