/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:53:53 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/03 17:53:57 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  check if is the given string valid as identifier
 */
bool	is_valid_identifier(char *string)
{
	if (string == NULL)
		return (false);
	if (!ft_isalpha(*string) && *string != '_')
		return (false);
	string++;
	while (*string)
	{
		if (!ft_isalnum(*string) && *string != '_')
			return (false);
		string++;
	}
	return (true);
}
