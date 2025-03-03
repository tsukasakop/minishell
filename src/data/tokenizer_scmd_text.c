/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_scmd_text.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:57:29 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/03 18:26:08 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_text_list	*new_text_list(char *str, int len)
{
	t_text_list	*node;

	node = malloc(sizeof(t_text_list));
	if (!node)
		return (NULL);
	node->text = ft_strndup(str, len);
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	add_text_list(t_text_list **head, t_text_list *new)
{
	t_text_list	*cur;

	if (!*head)
		*head = new;
	else
	{
		cur = *head;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
		new->prev = cur;
	}
}

int	get_redir_length(char *scmd_text)
{
	int	con;

	con = 0;
	if (*scmd_text == '>' || *scmd_text == '<')
	{
		con++;
		if (*(scmd_text + 1) && *scmd_text == *(scmd_text + 1))
			con++;
	}
	return (con);
}

t_text_list	*tokenizer_scmd_text(char *scmd_text)
{
	t_text_list	*new;
	t_text_list	*head;
	int			start;
	int			len;
	int			i;

	head = NULL;
	i = 0;
	while (scmd_text[i])
	{
		while (scmd_text[i] && isspace(scmd_text[i]))
			i++;
		if (!scmd_text[i])
			break ;
		start = i;
		if (ft_isdigit(scmd_text[i]))
		{
			while (scmd_text[i] && ft_isdigit(scmd_text[i]))
				i++;
			i += get_redir_length(&scmd_text[i]);
		}
		else if (scmd_text[i] == '>' || scmd_text[i] == '<')
			i += get_redir_length(&scmd_text[i]);
		else
		{
			while (scmd_text[i] && !isspace(scmd_text[i]) && scmd_text[i] != '>' && scmd_text[i] != '<')
				i++;
		}
		len = i - start;

		new = new_text_list(scmd_text + start, len);
		if (!new)
			return (NULL);
		add_text_list(&head, new);
	}
	return (head);
}
