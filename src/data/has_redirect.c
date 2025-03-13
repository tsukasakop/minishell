/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:46 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/13 18:04:33 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:has_redirect
 * ----------------------------
 * Returns true if there is a redirect, false if there is not.
 * TODO: return redirect type and rename to get_redirect_type
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
