/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:29:39 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/03 18:30:33 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: builtin_unset
 * ----------------------------
 *  unset environment varibales
 */
int	builtin_unset(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		ft_unsetenv(argv[i]);
		i++;
	}
	return (0);
}
