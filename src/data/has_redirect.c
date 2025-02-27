/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:46 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/27 03:09:45 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:has_redirect
 * ----------------------------
 * Returns true if there is a redirect, false if there is not.
 */
// bool	has_redirect(char *word)
// {
// 	size_t	len;

// 	len = ft_strlen(word);
// 	if (ft_strnstr(word, "<<", len) || ft_strnstr(word, "<", len) || \
// 		ft_strnstr(word, ">", len) || ft_strnstr(word, ">>", len))
// 		return (true);
// 	return (false);
// }

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
