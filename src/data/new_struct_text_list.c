/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_struct_text_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:56:50 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/03 19:56:58 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:new_struct_text_list
 * ----------------------------
 */
t_text_list	*new_struct_text_list(char *str, int len)
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
