/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_without_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:00:50 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/27 17:34:14 by mfunakos         ###   ########.fr       */
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
		handle_each_err_type(ERR_SYSCOLL, NULL);
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
