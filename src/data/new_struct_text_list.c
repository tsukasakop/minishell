/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_struct_text_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:56:50 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/29 20:25:54 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:new_struct_text_list
 * ----------------------------
 * Creates a new t_text_list node with a str
 */
t_text_list	*new_struct_text_list(char *str, size_t len)
{
	t_text_list	*node;

	node = ft_g_mmmalloc(sizeof(t_text_list));
	if (!node)
	{
		set_error_type(ERR_SYSCALL);
		perror_with_shellname(NULL);
		return (NULL);
	}
	node->text = ft_g_mmadd(ft_strndup(str, len));
	if (!node->text)
	{
		set_error_type(ERR_SYSCALL);
		perror_with_shellname(NULL);
		return (NULL);
	}
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
