/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:29:27 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/17 05:16:01 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Get path if the first word has not slash(/), otherwise duplicate first word
 *
 * const char *word: fitst word on the simple command
 */
const char	*get_path(const char *word)
{
	// TODO: resolve path if it has not slash
	return (ft_strdup(word));
}
