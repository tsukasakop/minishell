/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outerlen_between_quote.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:30:12 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/22 14:37:45 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:outerlen_between_quote
 * ----------------------------
 * Skips quoted text.
 * Returns its length, including the closing quote.
 */
size_t	outerlen_between_quote(char *scmd_text, char quote)
{
	size_t	i;

	i = 1;
	while (scmd_text[i] && scmd_text[i] != quote)
		i++;
	if (scmd_text[i] == quote)
		i++;
	return (i);
}
