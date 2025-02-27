/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ecmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:36:06 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/26 12:05:35 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:fill_ecmd
 * ----------------------------
 * Returns an array only strings without redirects.
 * ToDO:norminetteエラー
 */
char	**fill_ecmd(char **src, int wc)
{
	char	**ecmd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ecmd = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!ecmd)
		return (NULL);
	while (src[i])
	{
		if (has_redirect(src[i]) == true && src[i + 1])
			i++;
		else
		{
			ecmd[j] = ft_strdup(src[i]);
			if (!ecmd[j])
			{
				free_ecmd(ecmd);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	ecmd[j] = NULL;
	return (ecmd);
}
