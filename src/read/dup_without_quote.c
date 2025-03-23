/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_without_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:00:50 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/23 14:00:56 by tkondo           ###   ########.fr       */
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
		return (NULL);
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
