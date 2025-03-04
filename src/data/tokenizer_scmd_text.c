/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_scmd_text.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:57:29 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/05 00:38:35 by miyuu            ###   ########.fr       */
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
	size_t		len;
	int			i;

	head = NULL;
	i = 0;
	while (scmd_text[i])
	{
		while (ft_isifs(scmd_text[i]))
			i++;
		if (!scmd_text[i])
			break ;
		len = get_token_length(&scmd_text[i]);
		new = new_struct_text_list(scmd_text + i, len);
		if (!new)
			return (NULL);
		add_struct_text_list(&head, new);
		i += len;
	}
	return (head);
}
