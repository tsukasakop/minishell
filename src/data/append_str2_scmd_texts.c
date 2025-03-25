/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_str2_scmd_texts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:39:17 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/25 18:54:05 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:append_str2_scmd_texts
 * ----------------------------
 * Extracts len size of text from start.
 * And appends it to the pipeline.
 */
void	append_str2_scmd_texts(char ***scmd_texts, const char *text, \
								size_t start, size_t len)
{
	char	*sub;

	sub = ft_g_mmadd(ft_substr(text, start, len));
	if (!sub)
	{
		//TODO:SET errno
		perror_with_shellname(NULL);
		*scmd_texts = NULL;
		return ;
	}
	append_str(scmd_texts, sub);
}
