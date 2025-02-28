/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:46 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/28 18:48:25 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:has_redirect
 * ----------------------------
 * Returns true if there is a redirect, false if there is not.
 */
// bool	has_redirect(char *scmd)
// {
// 	size_t	len;

// 	len = ft_strlen(scmd);
// 	if (ft_strnstr(scmd, "<<", len) || ft_strnstr(scmd, "<", len) || \
// 		ft_strnstr(scmd, ">", len) || ft_strnstr(scmd, ">>", len))
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
