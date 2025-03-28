/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_variable_assignment.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:54:33 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/28 18:39:22 by mfunakos         ###   ########.fr       */
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
	{
		set_error_type(ERR_SYSCOLL);
		perror_with_shellname(NULL);
		return ;
	}
	if (!is_valid_identifier(*name))
	{
		*name = NULL;
		return ;
	}
	*value = ft_g_mmadd(ft_strdup(sep + 1));
	if (*value == NULL)
	{
		set_error_type(ERR_SYSCOLL);
		perror_with_shellname(NULL);
		*name = NULL;
	}
}
