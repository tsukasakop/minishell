/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_scmd_text.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:57:29 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/03 17:43:37 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_text_list	*new_node(char *str, int len)
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

void	add_node(t_text_list **head, t_text_list *new)
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
		if (scmd_text[i] == '>' || scmd_text[i] == '<')
		{
			len = 1;
			if (scmd_text[i + 1] && scmd_text[i + 1] == scmd_text[i])
				len = 2;
			i += len;
		}
		else
		{
			while (scmd_text[i] && !isspace(scmd_text[i]) && scmd_text[i] != '>' && scmd_text[i] != '<')
				i++;
			len = i - start;
		}
		new = new_node(scmd_text + start, len);
		if (!new)
			return (NULL);
		add_node(&head, new);
	}
	return (head);
}


+       //このsplitを変える↓
+       scmds = ft_split(scmd_text, ' ');
+       // t_text_list *scmds = tokenizer_scmd_text(scmd_text);
