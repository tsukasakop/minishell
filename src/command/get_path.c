/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:29:27 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/27 14:39:35 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Get path if the first ecmd has not slash(/), otherwise duplicate first ecmd
 *
 * const char *ecmd: fitst word on the simple command
 */
const char	*get_path(const char *ecmd)
{
	// TODO: resolve path if it has not slash
	return (ft_strdup(ecmd));
}
