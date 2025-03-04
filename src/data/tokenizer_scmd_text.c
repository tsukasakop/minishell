/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_scmd_text.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:57:29 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/04 13:31:32 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Tokenizes scmd_text and returns the head of the t_text_list.
 */
t_text_list	*tokenizer_scmd_text(char *scmd_text)
{
	t_text_list	*new;
	t_text_list	*head;
	int			start;
	size_t		len;
	int			i;

	head = NULL;
	i = 0;
	while (scmd_text[i])
	{
		while (ft_isspace(scmd_text[i]))
			i++;
		if (!scmd_text[i])
			break ;
		start = i;
		if (ft_isdigit(scmd_text[i]))
		{
			while (ft_isdigit(scmd_text[i]))
				i++;
			i += get_redir_length(&scmd_text[i]);
		}
		else if (scmd_text[i] == '>' || scmd_text[i] == '<')
			i += get_redir_length(&scmd_text[i]);
		else
		{
			while (scmd_text[i] && !ft_isspace(scmd_text[i]) && \
					scmd_text[i] != '>' && scmd_text[i] != '<')
				i++;
		}
		len = i - start;
		new = new_struct_text_list(scmd_text + start, len);
		if (!new)
			return (NULL);
		add_struct_text_list(&head, new);
	}
	return (head);
}
