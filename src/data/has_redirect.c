/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:46 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/26 12:08:19 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:has_redirect
 * ----------------------------
 * Returns true if there is a redirect, false if there is not.
 */
bool	has_redirect(char *s_cmd)
{
	size_t	len;

	len = ft_strlen(s_cmd);
	if (ft_strnstr(s_cmd, "<<", len) || ft_strnstr(s_cmd, "<", len) || \
		ft_strnstr(s_cmd, ">", len) || ft_strnstr(s_cmd, ">>", len))
		return (true);
	return (false);
}
