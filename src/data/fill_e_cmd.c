/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_e_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:36:06 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/26 12:05:35 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:fill_e_cmd
 * ----------------------------
 * Returns an array only strings without redirects.
 * ToDO:norminetteエラー
 */
char	**fill_e_cmd(char **src, int wc)
{
	char	**e_cmd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	e_cmd = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!e_cmd)
		return (NULL);
	while (src[i])
	{
		if (has_redirect(src[i]) == true && src[i + 1])
			i++;
		else
		{
			e_cmd[j] = ft_strdup(src[i]);
			if (!e_cmd[j])
			{
				free_e_cmd(e_cmd);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	e_cmd[j] = NULL;
	return (e_cmd);
}
