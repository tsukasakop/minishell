/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_str2_scmd_texts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:39:17 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 04:01:16 by miyuu            ###   ########.fr       */
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
		set_error_type(ERR_SYSCALL);
		print_errmsg_with_str(EM_SYSCALL, NULL);
		*scmd_texts = NULL;
		return ;
	}
	append_str(scmd_texts, sub);
}
