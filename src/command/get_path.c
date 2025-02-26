/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:29:27 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/26 12:12:21 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Get path if the first e_cmd has not slash(/), otherwise duplicate first e_cmd
 *
 * const char *e_cmd: fitst word on the simple command
 */
const char	*get_path(const char *e_cmd)
{
	// TODO: resolve path if it has not slash
	return (ft_strdup(e_cmd));
}
