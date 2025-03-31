/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_without_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:00:50 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/29 20:25:54 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: dup_without_quote
 * ----------------------------
 *  duplicate string without single/doubel quote
 */
char	*dup_without_quote(const char *hd_eof)
{
	char	*copy;
	char	*copy_head;

	copy = ft_g_mmmalloc(sizeof(char) * (ft_strlen(hd_eof) + 1));
	if (copy == NULL)
	{
		set_error_type(ERR_SYSCALL);
		perror_with_shellname(NULL);
		return (NULL);
	}
	copy_head = copy;
	while (*hd_eof)
	{
		if (!(*hd_eof == '\'' || *hd_eof == '\"'))
		{
			*copy = *hd_eof;
			copy++;
		}
		hd_eof++;
	}
	*copy = '\0';
	return (copy_head);
}
