/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_variable_assignment.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:54:33 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/03 17:54:42 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  load variable assignemnt string into name and value
 */
void	load_variable_assignment(char *string, char **name, char **value)
{
	char	*sep;

	*name = NULL;
	*value = NULL;
	sep = ft_strchr(string, '=');
	if (sep == NULL)
		return ;
	*name = ft_g_mmadd(ft_strndup(string, sep - string));
	if (*name == NULL)
		return ;
	if (!is_valid_identifier(*name))
	{
		*name = NULL;
		return ;
	}
	*value = ft_g_mmadd(ft_strdup(sep + 1));
	if (*value == NULL)
	{
		*name = NULL;
	}
}
