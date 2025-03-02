/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:46 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/02 18:17:11 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:has_redirect
 * ----------------------------
 * Returns true if there is a redirect, false if there is not.
 */
char	*has_redirect(char *word)
{
	size_t	len;

	len = ft_strlen(word);
	if (ft_strnstr(word, "<<", len))
		return (ft_strnstr(word, "<<", len));
	else if (ft_strnstr(word, ">>", len))
		return (ft_strnstr(word, ">>", len));
	else if (ft_strnstr(word, "<", len))
		return (ft_strnstr(word, "<", len));
	else if (ft_strnstr(word, ">", len))
		return (ft_strnstr(word, ">", len));
	return (NULL);
}
